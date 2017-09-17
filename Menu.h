#pragma once
#include "ElementoGUI.h"
#include <vector>
#include <string>

using namespace std;

class Menu : public ElementoGUI{
private:
  vector<string> elementos;
  bool activo;
  bool visible;
  int indice;
  int tipo;
  int wrap;

public:
  vector<string> getElementos();
  bool isActivo();
  bool isVisible();
  int getIndice();
  int getTipo();
  int getWrap();

  void setElementos(vector<ElementoMenu>);
  void setActivo(bool);
  void setVisible(bool);
  void setIndice(int);
  void setTipo(int);
  void setWrap(int);

  SDL_Surface* toSuperficie();
  bool refrescar();

  void indiceUp();
  void indiceDown();
};
