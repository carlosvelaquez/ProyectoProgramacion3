#pragma once
#include "ElementoGUI.h"
#include <vector>
#include "Texto.h"
#include "Sonido.h"

using namespace std;

class Menu : public ElementoGUI{
private:
  vector<Texto> elementos;
  bool activo;
  bool visible;
  int indice;
  int tipo;
  int wrap;

  SDL_Color colorActivo;
  SDL_Color colorInactivo;

  Sonido* sonidoMove;
  Sonido* sonidoSelect;

public:
  Menu();

  vector<Texto> getElementos();
  bool isActivo();
  bool isVisible();
  int getIndice();
  int getTipo();
  int getWrap();

  void setElementos(vector<Texto>);
  void setActivo(bool);
  void setVisible(bool);
  void setIndice(int);
  void setTipo(int);
  void setWrap(int);

  SDL_Surface* toSuperficie();
  bool refrescar();

  void indiceUp();
  void indiceDown();
  int trap();

  void addElemento(Texto);
  void chop();
  void clear();

  SDL_Color getColorActivo();
  SDL_Color getColorInactivo();

  void setColorActivo(SDL_Color);
  void setColorInactivo(SDL_Color);
};
