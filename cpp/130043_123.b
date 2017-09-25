class Espacio
!!!145019.cpp!!!	Espacio(in nAltura : int, in nAnchura : int)
  altura = nAltura;
  anchura = nAnchura;
!!!145147.cpp!!!	Espacio(in nAltura : int, in nAnchura : int, in nProps : vector<Prop>)
  altura = nAltura;
  anchura = nAnchura;
  props = nProps;
!!!145275.cpp!!!	getProps() : vector<Prop>
  return props;
!!!145403.cpp!!!	getAltura() : int
  return altura;
!!!145531.cpp!!!	getAnchura() : int
  return anchura;
!!!145659.cpp!!!	setProps(in nProps : vector<Prop>) : void
  props = nProps;
!!!145787.cpp!!!	setAltura(in nAltura : int) : void
  altura = nAltura;
!!!145915.cpp!!!	setAnchura(in nAnchura : int) : void
  anchura = nAnchura;
!!!146043.cpp!!!	addProp(in nProp : Prop) : void
  props.push_back(nProp);
