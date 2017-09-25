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
  virtual bool cargar() = 0;
  virtual bool reproducir() = 0;
  virtual bool parar() = 0;
  virtual bool verificar() = 0;
  virtual string identificar() = 0;
  virtual void liberar() = 0;

  bool isCargado();
};
