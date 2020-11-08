open Renu.LtermHelper;
open Renu.Render;

module ThreeBox = {
  let container =
    style(~marginTop=4, ~marginLeft=5, ~height=10, ~padding=2, ());

  let createElement = (~children=[], ()) =>
    <Div style=container>
      <Div> {str("one")} </Div>
      <Div> {str("five")} </Div>
      <Div> {str("seventeen")} </Div>
      <Div> {str("hundred")} </Div>
    </Div>;
};

let app = <ThreeBox />;
Renu.render(app);
