#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Imagen{
private:
  string ruta;
  SDL_Surface* superficie = NULL;
  cargada = false;

public:
  Imagen(string);

  string getRuta();
  SDL_Surface* getSuperficie();
  void setRuta(string);
  bool recargar();

  operator SDL_Surface* const{ return superficie };

  ~Imagen();
};
