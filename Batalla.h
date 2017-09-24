#pragma once
#include "Enemigo.h"
#include "Imagen.h"
#include "Musica.h"

class Batalla{

private:
  Enemigo* enemigo;
  Imagen fondo;
  Musica* musica;
  Sprite* decoraciones;
  bool activa;
  int turno;

public:
  Batalla(Enemigo*, Imagen, Musica*, Sprite*);

  Enemigo* getEnemigo();
  Imagen getFondo();
  Musica* getMusica();
  Sprite* getDecoraciones();
  bool isActiva();

  void setEnemigo(Enemigo*);
  void setFondo(Imagen);
  void setMusica(Musica*);
  void setDecoraciones(Sprite*);
  void setActiva(bool);

  ~Batalla();
};
