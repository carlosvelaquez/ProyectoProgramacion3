#pragma once
#include "Audio.h"

class Musica : public Audio{
private:
  Mix_Music* musica;

public:
  Musica(string);

  bool pausar();
  bool resumir();
  void parar();

  bool reproducir();
  bool cargar();

  ~Musica();
};
