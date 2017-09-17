#include "Menu.h"

vector<string> Menu::getElementos(){
  return elementos;
}

bool Menu::isActivo(){
  return activo;
}

bool Menu::isVisible(){
  return visible;
}

int Menu::getIndice(){
  return indice;
}

int Menu::getTipo(){
  return tipo;
}

int Menu::getWrap(){
  return wrap;
}

void Menu::setElementos(vector<ElementoMenu> nElementos){
  elementos = nElementos;
}

void Menu::setActivo(bool nActivo){
  activo = nActivo;
}

void Menu::setVisible(bool nVisible){
  visible = nVisible;
}

void Menu::setIndice(int nIndice){
  indice = nIndice;
}

void Menu::setTipo(int nTipo){
  tipo = nTipo;
}

void Menu::setWrap(int nWrap){
  wrap = nWrap;
}

SDL_Surface* Menu::toSuperficie(){

}

bool Menu::refrescar(){
  std::cout << "[Menu] Refrescando..." << '\n';
  return true;
}

void Menu::indiceUp(){
  if (indice + 1 < elementos.size()) {
    indice++;
  }else{
    indice = 0;
  }
}

void Menu::indiceDown(){
  if (indice - 1 < 0) {
    indice = elementos.size() - 1;
  }else{
    indice--;
  }
}
