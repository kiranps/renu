let info = contents =>
  try({
    let out = open_out("/tmp/renu.log");
    output_string(out, contents);
    close_out(out);
    true;
  }) {
  | _ => false
  };
