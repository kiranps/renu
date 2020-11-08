open Flex;
open Lwt;
module Encoding = FixedEncoding;

module Node = {
  type context = ref(option(string));
  let nullContext = {contents: None};
};

module Layout = Layout.Create(Node, Encoding);
module LayoutSupport = Layout.LayoutSupport;
module LayoutTypes = LayoutSupport.LayoutTypes;
open LayoutSupport.LayoutTypes;
open LTerm_widget;

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

type style = LayoutTypes.cssStyle;

type element =
  | String(string)
  | View;

type node =
  | Builtin(element, list(node), option(style));

module Div = {
  let createElement = (~children=[], ~style=?, ()) =>
    Builtin(View, children, style);
};

let style =
    (
      ~height=Encoding.cssUndefined,
      ~padding=Encoding.cssUndefined,
      ~flexDirection=LayoutTypes.Row,
      ~marginLeft=Encoding.cssUndefined,
      ~marginTop=Encoding.cssUndefined,
      (),
    ) => {
  let ret: style = {
    ...LayoutSupport.defaultStyle,
    flexDirection,
    height,
    padding,
    marginLeft,
    marginTop,
  };

  ret;
};
