#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>

using namespace std;

class Imagen{
private:
  string ruta;
  SDL_Surface* superficie = NULL;
  bool cargada = false;

public:
  Imagen();
  Imagen(string);

  string getRuta();
  SDL_Surface* getSuperficie();
  void setRuta(string);
  bool recargar();

  virtual SDL_Surface* toSuperficie();

  ~Imagen();
};
