#pragma once
#include "Enemigo.h"
#include "Imagen.h"

class Batalla{

private:
  Enemigo enemigo;
  Imagen fondo;
  Sonido musica;
  Sprite* decoraciones;
  bool activa;

public:
  Batalla(Enemigo, Imagen, Sonido, Sprite*);

  Enemigo getEnemigo();
  Imagen getFondo();
  Sonido getMusica();
  Sprite* getDecoraciones();
  bool isActiva();

  void setEnemigo(Enemigo);
  void setFondo(Imagen);
  void setMusica(Sonido);
  void setDecoraciones(Sprite*);
  void setActiva(bool);

  ~Batalla();
};
