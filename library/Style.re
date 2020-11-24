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

type style = LayoutTypes.cssStyle;

let defaultStyle = LayoutSupport.defaultStyle;

let style =
    (
      ~flex=Encoding.cssUndefined,
      ~width=Encoding.cssUndefined,
      ~height=Encoding.cssUndefined,
      ~padding=Encoding.cssUndefined,
      ~flexDirection=LayoutTypes.Row,
      ~marginLeft=Encoding.cssUndefined,
      ~marginTop=Encoding.cssUndefined,
      (),
    ) => {
  let ret: style = {
    ...LayoutSupport.defaultStyle,
    flex,
    flexDirection,
    width,
    height,
    padding,
    marginLeft,
    marginTop,
  };

  ret;
};
