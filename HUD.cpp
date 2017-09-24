#include "HUD.h"

HUD::HUD(){
  elementos.clear();
}

HUD::HUD(vector<ElementoGUI*> nElementos){
  elementos = nElementos;
}

void HUD::addElemento(ElementoGUI* nElemento){
  elementos.push_back(nElemento);
}

vector<ElementoGUI*> HUD::getElementos(){
  return elementos;
}

void HUD::setElementos(vector<ElementoGUI*> nElementos){
  elementos = nElementos;
}

void HUD::removeElemento(int indice){
  elementos.erase(elementos.begin() + indice);
}

HUD::~HUD(){
  for (int i = 0; i < elementos.size(); i++) {
    delete elementos[i];
  }
}
