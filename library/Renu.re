module Types = Types;
module Render = Render;
module Draw = Draw;

open Flex;
module Encoding = FixedEncoding;
module Style = Style;
open Encoding;

open Types;
open Render;
open Style;

let create_tree = (app, term) => {
  let (ui, matrix) = term;
  let size = LTerm_ui.size(ui);
  let body_style = Some(style(~width=size.cols, ~height=size.rows, ()));
  let canvas = Node(Element, [app], body_style);

  let t1 = renderer(canvas);
  Layout.layoutNode(t1, cssUndefined, cssUndefined, Ltr);
  let t2 = drawTree(t1);
  t2(term);
};

let _render = app => {
  create_ui(term => create_tree(app, term));
};

let render = app => Lwt_main.run(_render(app));
