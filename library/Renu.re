module LtermHelper = LtermHelper;
module Render = Render;
module Draw = Draw;

open Flex;
module Encoding = FixedEncoding;
open Encoding;

open LtermHelper;
open Render;

let _render = app => {
  let t1 = renderer(app);
  Layout.layoutNode(t1, cssUndefined, cssUndefined, Ltr);
  let t2 = drawTree(t1);
  render(t2);
};

let render = app => Lwt_main.run(_render(app));
