open Types;
open Style;
module LayoutSupport = Style.LayoutSupport;

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

let rec renderer = node =>
  switch (node) {
  | Node(Element, [child], style) =>
    switch (child) {
    | Node(Text(value), _, _) =>
      createTextNode(
        value,
        LayoutSupport.defaultStyle,
        measureText(String.length(value) + 2, 1),
      )
    | _ => renderer(child)
    }
  | Node(Element, children, style) =>
    createDivNode(List.map(renderer, children), style)
  | Node(Text(value), _, _) =>
    createTextNode(
      value,
      LayoutSupport.defaultStyle,
      measureText(String.length(value) + 2, 1),
    )
  };

let rec renderer = node =>
  switch (node) {
  | Node(Element, children, style) =>
    createDivNode(List.map(renderer, children), style)
  | Node(Text(value), _, _) =>
    createTextNode(
      value,
      LayoutSupport.defaultStyle,
      measureText(String.length(value) + 2, 1),
    )
  };
