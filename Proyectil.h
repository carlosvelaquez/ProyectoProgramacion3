#pragma once
#include "Sprite.h"

class Proyectil{
private:
  Sprite sprite;
  int velocidad;
  int posicionX;
  int posicionY;
  int direccion;
public:
  Sprite getSprite();
  int getVelocidad();
  int getPosicionX();
  int getPosicionY();
  int getDireccion();

  void setSprite(Sprite);
  void setVelocidad(int);
  void setPosicionX(int);
  void setPosicionY(int);
  void setDireccion(int);
};
