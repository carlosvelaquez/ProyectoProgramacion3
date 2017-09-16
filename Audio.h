#pragma once

#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <iostream>
#include <string>

using namespace std;

class Audio{
protected:
  string ruta;
  bool cargado = false;

public:
  virtual bool reproducir() = 0;
  virtual bool cargar() = 0;

  bool isCargado();
};
