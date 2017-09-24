#pragma once
#include "Audio.h"

class Sonido : public Audio{
private:
  Mix_Chunk* sonido;

public:
  Sonido();
  Sonido(string);

  bool reproducir();
  bool cargar();

  ~Sonido();
};
