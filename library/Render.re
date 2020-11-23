open Flex;
open Lwt;
open Types;
open Draw;
open Style;

module LayoutSupport = Style.LayoutSupport;

let ctrl_c = LTerm_key.Char(CamomileLibrary.UChar.of_char('c'));

let rec close = ui =>
  LTerm_ui.wait(ui)
  >>= (
    fun
    | LTerm_event.Key({control: true, code: ctrl_c, _}) => return()
    | _ => close(ui)
  );

let create_ui = app =>
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

let str = x => Node(Text(x), [], None);

let defaultPosition = {tx: 0, ty: 0};

let rec renderer = node =>
  switch (node) {
  | Node(Element, [child], None) =>
    switch (child) {
    | Node(Text(value), _, _) =>
      createTextNode(
        value,
        LayoutSupport.defaultStyle,
        measureText(String.length(value) + 2, 1),
      )
    | _ => renderer(child)
    }
  | Node(Element, children, Some(style)) =>
    createDivNode(List.map(renderer, children), style)
  | Node(Element, children, None) =>
    createDivNode(List.map(renderer, children), LayoutSupport.defaultStyle)
  | Node(Text(value), _, _) =>
    createTextNode(
      value,
      LayoutSupport.defaultStyle,
      measureText(String.length(value), 1),
    )
  };

let getPosition = (layout: LayoutSupport.LayoutTypes.cssLayout, prevPosition) => {
  tx: layout.top + prevPosition.tx,
  ty: layout.left + prevPosition.ty,
};

let createStyle = (layout: LayoutSupport.LayoutTypes.cssLayout, parentLayout) => {
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
