#pragma once
#include "ElementoGUI.h"
#include "Sprite.h"
#include <vector>
#include <thread>

class Soul : public ElementoGUI{
private:
  Sprite sprite;
  int velocidad;
  int velocidadBlink;
  long duracionBlink;
  bool visible;
  bool salirTrap;

  SDL_Rect bounds;

public:
  Soul();

  Sprite getSprite();
  int getVelocidad();
  int getVelocidadBlink();
  long getDuracionBlink();

  void setSprite(Sprite);
  void setVelocidad(int);
  void setVelocidadBlink(int);
  void setDuracionBlink(long);

  void trap();
  void blink();
  void comenzarBlink();
  void mover(int);
  void terminarTrap();
  void centrar();

  SDL_Rect getBounds();
  void setBounds(SDL_Rect);

  SDL_Surface* toSuperficie();
  bool refrescar();
};
