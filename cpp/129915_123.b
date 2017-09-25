class HUD
!!!146171.cpp!!!	HUD()
  elementos.clear();
!!!146299.cpp!!!	HUD(in nElementos : vector<ElementoGUI*>)
  elementos = nElementos;
!!!146427.cpp!!!	addElemento(inout nElemento : ElementoGUI) : void
  elementos.push_back(nElemento);
!!!146555.cpp!!!	getElementos() : vector<ElementoGUI*>
  return elementos;
!!!146683.cpp!!!	setElementos(in nElementos : vector<ElementoGUI*>) : void
  elementos = nElementos;
!!!146811.cpp!!!	removeElemento(in indice : int) : void
  elementos.erase(elementos.begin() + indice);
!!!146939.cpp!!!	~HUD()
  for (int i = 0; i < elementos.size(); i++) {
    delete elementos[i];
  }
