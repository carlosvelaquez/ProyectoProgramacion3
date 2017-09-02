#pragma once
#include "Imagen.h"
#include "SDL/SDL.h"

class Sprite{
private:
  Imagen fuente;
  SDL_Rect* clip = NULL;
  SDL_Surface* superficie = NULL;

public:
  Sprite(string);
  Sprite(Imagen);
  Sprite(Imagen, SDL_Rect*);
  Imagen getFuente();
  SDL_Rect* getClip();

  void setFuente(Imagen);
  void setClip(SDL_Rect*);
  void setClip(int, int);

  ~Sprite();
};
