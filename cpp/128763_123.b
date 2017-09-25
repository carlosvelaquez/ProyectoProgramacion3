class ElementoGUI
!!!138875.cpp!!!	getAnchura() : int
  return anchura;
!!!139003.cpp!!!	getAltura() : int
  return altura;
!!!139131.cpp!!!	getPosicionX() : int
  return posicionX;
!!!139259.cpp!!!	getPosicionY() : int
  return posicionY;
!!!139387.cpp!!!	setAnchura(in nAnchura : int) : void
  anchura = nAnchura;
!!!139515.cpp!!!	setAltura(in nAltura : int) : void
  altura = nAltura;
!!!139643.cpp!!!	setPosicionX(in posX : int) : void
  posicionX = posX;
!!!139771.cpp!!!	setPosicionY(in posY : int) : void
  posicionY = posY;
!!!139899.cpp!!!	centrar() : void
  posicionX = 320 - (anchura/2);
  posicionY = 240 - (altura/2);
!!!140027.cpp!!!	setVisible(in nVisible : bool) : void
  visible = nVisible;
!!!140155.cpp!!!	isVisible() : bool
  return visible;
