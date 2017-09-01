#pragma once

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <string>

using namespace std;

class Texto{
private:
  string texto;
  int size;
  int length;
  int wrap;
  SDL_Color color;
  TTF_Font* font;
  string rutaFont;

public:
  Texto();
  Texto(string);
  Texto(string, int);
  Texto(string, int, int);
  Texto(string, int, int, SDL_Color);
  Texto(string, int, int, SDL_Color, string);

  string getTexto();
  int getSize();
  int getLength();
  int getWrap();
  SDL_Color getColor();
  TTF_Font* getFont();
  SDL_Surface* toSuperficie();

  void setTexto(string);
  void setSize(int);
  void setWrap(int);
  void setColor(SDL_Color);
  void setFont(TTF_Font);

  int getDimX();
  int getDimY();

  void cargarFont(string);
  void refrescar();

  ~Texto();
};
