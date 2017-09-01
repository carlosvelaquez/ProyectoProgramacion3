#pragma once
#include "Sprite.h"

class Prop{
private:
  int altura;
  int anchura;
  int posicionX;
  int posicionY;
  Sprite sprite;
  bool esSolido;
public:
  int getAltura();
  int getAnchura();
  int getPosicionX();
  int getPosicionY();
  Sprite getSprite();
  bool isSolido();

  void setAltura(int);
  void setAnchura(int);
  void setPosicionX(int);
  void setPosicionY(int);
  void setSprite(Sprite);
  void setSolido(bool);
};