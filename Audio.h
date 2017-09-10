#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <iostream>
#include <string>

using namespace std;

class Audio{
protected:
  string ruta;
  bool cargado;

public:
  virtual bool reproducir() = 0;
  virtual bool cargar() = 0;
};
