open Renu.Types;
open LTerm_style;

let app = term => {
  let dim1 = {x: 0, y: 0, height: 1, width: 120};

  let style = {
    bold: None,
    underline: None,
    blink: None,
    reverse: None,
    foreground: Some(LTerm_style.white),
    background: Some(LTerm_style.rgb(0, 255, 255)),
  };

  Renu.Draw.draw_rect(term, dim1, ~style, ());
};

Renu.Render.create_ui(app) |> Lwt_main.run;
