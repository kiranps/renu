/*module LayoutSupport = Style.LayoutSupport;*/
/*let str = x => Node(Text(x), [], None);*/
/*let defaultPosition = {tx: 0, ty: 0};*/
/*let getPosition = (layout: LayoutSupport.LayoutTypes.cssLayout, prevPosition) => {*/
/*tx: layout.top + prevPosition.tx,*/
/*ty: layout.left + prevPosition.ty,*/
/*};*/
/*let createStyle = (layout: LayoutSupport.LayoutTypes.cssLayout, parentLayout) => {*/
/*x: layout.top + parentLayout.tx,*/
/*y: layout.left + parentLayout.ty,*/
/*width: layout.width,*/
/*height: layout.height,*/
/*};*/
/*let rec drawTree =*/
/*(*/
/*node: LayoutSupport.LayoutTypes.node,*/
/*~prevPosition=defaultPosition,*/
/*term,*/
/*) => {*/
/*switch (node.context.contents) {*/
/*| Some(value) =>*/
/*drawString(node.layout.top, node.layout.left, prevPosition, term, value);*/
/*drawRect(node.layout, prevPosition, term);*/
/*| None => drawRect(node.layout, prevPosition, term)*/
/*};*/
/*let position = getPosition(node.layout, prevPosition);*/
/*Array.iter(n => drawTree(n, ~prevPosition=position, term), node.children);*/
/*();*/
/*};*/
