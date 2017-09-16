#pragma once
#include "ElementoGUI.h"
#include "Sprite.h"
#include "Sonido.h"
#include <vector>

class AtaqueJugador : public ElementoGUI{
private:
  Sonido* sonido;
  vector<Sprite> frames;
  long velocidad;
  int indiceActual;

public:
  AtaqueJugador(Sonido*, vector<Sprite>, long);

  Sonido* getSonido();
  vector<Sprite> getFrames();
  long getVelocidad();
  int getIndiceActual();

  void setSonido(Sonido*);
  void setFrames(vector<Sprite>);
  void setVelocidad(long);
  void setIndiceActual(int);

  SDL_Surface* toSuperficie();
  bool refrescar();

  void reproducir();
  void cicloIndice();

  ~AtaqueJugador();
};
