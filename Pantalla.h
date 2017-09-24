#pragma once
#include "Escenario.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "Texto.h"

using namespace std;

class Pantalla{
private:
  Escenario* escenario;
  int altura;
  int anchura;
  SDL_Surface* superficie = NULL;

public:
  Pantalla(int, int);

  Escenario* getEscenario();
  int getAltura();
  int getAnchura();

  void setEscenario(Escenario*);
  void setAltura(int);
  void setAnchura(int);

  bool refrescar();
  bool limpiar();
  void aplicarSuperficie(SDL_Surface*, int, int);
  void fade(int, long);

  ~Pantalla();
};
