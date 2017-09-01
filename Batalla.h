#pragma once
#include "Enemigo.h"
#include "Imagen.h"

class Batalla{
private:
  Enemigo enemigo;
  Imagen fondo;
  Sonido musica;
  bool termino;
public:
  Enemigo getEnemigo();
  Imagen getFondo();
  Sonido getMusica();
  bool termino();

  void setEnemigo(Enemigo);
  void setFondo(Imagen);
  void setMusica(Sonido);
  void setTermino(bool);
};
