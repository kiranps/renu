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
  | Node(element, list(node), option(style));

module Div = {
  let createElement = (~children=[], ~style=?, ()) =>
    Node(Element, children, style);
};
