/*let createDivNode = (children, style) =>*/
/*LayoutSupport.createNode(*/
/*~withChildren=Array.of_list(children),*/
/*~andStyle=style,*/
/*{contents: None},*/
/*);*/
/*let createTextNode = (text, style, measure) =>*/
/*LayoutSupport.createNode(*/
/*~withChildren=[||],*/
/*~andStyle=style,*/
/*~andMeasure=measure,*/
/*{contents: Some(text)},*/
/*);*/
/*let measureText = (w, h, _, _, _, _, _) => {*/
/*LayoutTypes.width: w,*/
/*LayoutTypes.height: h,*/
/*};*/
/*let rec renderer = node =>*/
/*switch (node) {*/
/*| Node(Element, [child], None) =>*/
/*switch (child) {*/
/*| Node(Text(value), _, _) =>*/
/*createTextNode(*/
/*value,*/
/*LayoutSupport.defaultStyle,*/
/*measureText(String.length(value) + 2, 1),*/
/*)*/
/*| _ => renderer(child)*/
/*}*/
/*| Node(Element, children, Some(style)) =>*/
/*createDivNode(List.map(renderer, children), style)*/
/*| Node(Element, children, None) =>*/
/*createDivNode(List.map(renderer, children), LayoutSupport.defaultStyle)*/
/*| Node(Text(value), _, _) =>*/
/*createTextNode(*/
/*value,*/
/*LayoutSupport.defaultStyle,*/
/*measureText(String.length(value), 1),*/
/*)*/
/*};*/
