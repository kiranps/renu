open Renu.Types;
open Renu.Render;
open Renu.Style;

module ThreeBox = {
  let container =
    style(~flex=1, ~marginTop=0, ~marginLeft=0, ~height=10, ~padding=2, ());

  let createElement = (~children=[], ()) =>
    <Div style=container>
      <Div> {str("one")} </Div>
      <Div> {str("five")} </Div>
      <Div> {str("seventeen")} </Div>
      <Div> {str("hundred")} </Div>
      <Div> {str("hundred")} </Div>
      <Div> {str("hundred")} </Div>
      <Div> {str("hundred")} </Div>
    </Div>;
};

let app = <ThreeBox />;
Renu.render(app);
