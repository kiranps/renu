open Types;
open LTerm_style;
open LTerm_draw;
open Style;

let unsafe_get = (matrix, line, column) =>
  Array.unsafe_get(Array.unsafe_get(matrix, line), column);

let fill_style_ = (matrix, rect: LTerm_geom.rect, style) =>
  for (row in rect.row1 to rect.row2 - 1) {
    for (col in rect.col1 to rect.col2 - 1) {
      set_style(unsafe_get(matrix, row, col), style);
    };
  };

let draw_rect = (term, dimensions, ~style=?, ()) => {
  let (ui, matrix) = term;
  let size = LTerm_ui.size(ui);
  let ctx = LTerm_draw.context(matrix, size);

  let rect: LTerm_geom.rect = {
    row1: dimensions.x,
    col1: dimensions.y,
    row2: dimensions.x + dimensions.height,
    col2: dimensions.y + dimensions.width,
  };

  switch (style) {
  | Some(style_) => fill_style_(matrix, rect, style_)
  | None => ()
  };

  LTerm_draw.draw_frame(ctx, rect, LTerm_draw.Light);
};

let drawRect =
    (layout: Style.LayoutSupport.LayoutTypes.cssLayout, parentLayout, term) => {
  let style = {
    x: layout.top + parentLayout.tx,
    y: layout.left + parentLayout.ty,
    width: layout.width,
    height: layout.height,
  };
  draw_rect(term, style, ());
};

let drawString = (row, column, parentLayout, term, value) => {
  let (ui, matrix) = term;
  let size = LTerm_ui.size(ui);
  let ctx = LTerm_draw.context(matrix, size);
  let row_ = row + parentLayout.tx + 1;
  let column_ = column + parentLayout.ty + 1;
  LTerm_draw.draw_string(ctx, row_, column_, Zed_string.of_utf8(value));
};
