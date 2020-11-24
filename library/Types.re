open Style;

type dim = {
  x: int,
  y: int,
  height: int,
  width: int,
};

type position = {
  tx: int,
  ty: int,
};

type element =
  | Text(string)
  | Element;

type node =
  | Node(element, list(node), style);

module Div = {
  let createElement = (~children=[], ~style=defaultStyle, ()) =>
    Node(Element, children, style);
};

let str = x => Node(Text(x), [], defaultStyle);
