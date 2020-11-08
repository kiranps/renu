open LtermHelper;

let draw_rect = (term, dimensions) => {
  let (ui, matrix) = term;
  let size = LTerm_ui.size(ui);
  let ctx = LTerm_draw.context(matrix, size);
  LTerm_draw.draw_frame(
    ctx,
    {
      row1: dimensions.x,
      col1: dimensions.y,
      row2: dimensions.x + dimensions.height,
      col2: dimensions.y + dimensions.width,
    },
    LTerm_draw.Light,
  );
  ();
};

let drawRect =
    (
      layout: LtermHelper.LayoutSupport.LayoutTypes.cssLayout,
      parentLayout,
      term,
    ) => {
  let style = {
    x: layout.top + parentLayout.tx,
    y: layout.left + parentLayout.ty,
    width: layout.width,
    height: layout.height,
  };
  draw_rect(term, style);
};

let drawString = (row, column, parentLayout, term, value) => {
  let (ui, matrix) = term;
  let size = LTerm_ui.size(ui);
  let ctx = LTerm_draw.context(matrix, size);
  let row_ = row + parentLayout.tx + 1;
  let column_ = column + parentLayout.ty + 1;
  LTerm_draw.draw_string(ctx, row_, column_, Zed_string.of_utf8(value));
};
