open Flex;
open Lwt;
open LtermHelper;
open Draw;

let div = (style, ~children=[], term) => {
  draw_rect(term, style);
  List.iter(item => item(term), children);
};

let ctrl_c = LTerm_key.Char(CamomileLibrary.UChar.of_char('c'));

let rec close = ui =>
  LTerm_ui.wait(ui)
  >>= (
    fun
    | LTerm_event.Key({control: true, code: ctrl_c, _}) => return()
    | _ => close(ui)
  );

let render = app =>
  Lazy.force(LTerm.stdout)
  >>= (
    term =>
      LTerm_ui.create(term, (ui, matrix) => app((ui, matrix)))
      >>= (ui => Lwt.finalize(() => close(ui), () => LTerm_ui.quit(ui)))
  );

let createDivNode = (children, style) =>
  LayoutSupport.createNode(
    ~withChildren=Array.of_list(children),
    ~andStyle=style,
    {contents: None},
  );

let createTextNode = (text, style, measure) =>
  LayoutSupport.createNode(
    ~withChildren=[||],
    ~andStyle=style,
    ~andMeasure=measure,
    {contents: Some(text)},
  );

let measureText = (w, h, _, _, _, _, _) => {
  LayoutTypes.width: w,
  LayoutTypes.height: h,
};

let str = x => Builtin(String(x), [], None);

let defaultPosition = {tx: 0, ty: 0};

let rec renderer = node =>
  switch (node) {
  | Builtin(View, [child], None) =>
    switch (child) {
    | Builtin(String(value), _, _) =>
      createTextNode(
        value,
        LayoutSupport.defaultStyle,
        measureText(String.length(value) + 2, 1),
      )
    | _ => renderer(child)
    }
  | Builtin(View, children, Some(style)) =>
    createDivNode(List.map(renderer, children), style)
  | Builtin(View, children, None) =>
    createDivNode(List.map(renderer, children), LayoutSupport.defaultStyle)
  | Builtin(String(value), _, _) =>
    createTextNode(
      value,
      LayoutSupport.defaultStyle,
      measureText(String.length(value), 1),
    )
  };

let getPosition =
    (layout: LtermHelper.LayoutSupport.LayoutTypes.cssLayout, prevPosition) => {
  tx: layout.top + prevPosition.tx,
  ty: layout.left + prevPosition.ty,
};

let createStyle =
    (layout: LtermHelper.LayoutSupport.LayoutTypes.cssLayout, parentLayout) => {
  x: layout.top + parentLayout.tx,
  y: layout.left + parentLayout.ty,
  width: layout.width,
  height: layout.height,
};

let rec drawTree =
        (
          node: LayoutSupport.LayoutTypes.node,
          ~prevPosition=defaultPosition,
          term,
        ) => {
  switch (node.context.contents) {
  | Some(value) =>
    drawString(node.layout.top, node.layout.left, prevPosition, term, value);
    drawRect(node.layout, prevPosition, term);
  | None => drawRect(node.layout, prevPosition, term)
  };
  let position = getPosition(node.layout, prevPosition);
  Array.iter(n => drawTree(n, ~prevPosition=position, term), node.children);
  ();
};
