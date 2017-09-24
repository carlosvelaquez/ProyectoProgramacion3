#pragma once
#include "SDL/SDL.h"
#include "Imagen.h"

class ElementoGUI{
protected:
  int anchura = 0;
  int altura = 0;
  int posicionX = 0;
  int posicionY = 0;

public:
  int getAnchura();
  int getAltura();
  int getPosicionX();
  int getPosicionY();

  void setAnchura(int);
  void setAltura(int);
  void setPosicionX(int);
  void setPosicionY(int);
  void centrar();

  virtual SDL_Surface* toSuperficie() = 0;
  virtual bool refrescar() = 0;
};
