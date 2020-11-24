open Lwt;

let ctrl_c = LTerm_key.Char(CamomileLibrary.UChar.of_char('c'));

let rec close = ui =>
  LTerm_ui.wait(ui)
  >>= (
    fun
    | LTerm_event.Key({control: true, code: ctrl_c, _}) => return()
    | _ => close(ui)
  );

let create_ui = app =>
  Lazy.force(LTerm.stdout)
  >>= (
    term =>
      LTerm_ui.create(term, (ui, matrix) => app((ui, matrix)))
      >>= (ui => Lwt.finalize(() => close(ui), () => LTerm_ui.quit(ui)))
  );
