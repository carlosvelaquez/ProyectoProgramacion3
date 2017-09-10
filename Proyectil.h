#pragma once
#include "Sprite.h"
#include <thread>
#include <chrono>

using namespace std;

class Proyectil{
private:
  Sprite sprite;
  int anchura;
  int altura;
  int velocidadX;
  int velocidadY;
  int posicionX;
  int posicionY;
  long vida;
  bool activo = false;

public:
  Proyectil(Sprite, int, int, int, int, long);
  Proyectil(Sprite, int, int);

  Sprite getSprite();
  int getAnchura();
  int getAltura();
  int getVelocidadX();
  int getVelocidadY();
  int getPosicionX();
  int getPosicionY();

  void setSprite(Sprite);
  void setVelocidadX(int);
  void setVelocidadY(int);
  void setPosicionX(int);
  void setPosicionY(int);

  void activar();
  void ejecutar();
};
