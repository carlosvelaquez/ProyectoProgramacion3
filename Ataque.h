#pragma once
#include "Sprite.h"
#include "Proyectil.h"

class Ataque{
private:
  Proyectil proyectil;
  long duracion;
public:
  Proyectil getProyectil();
  long getDuracion();

  void setProyectil(Proyectil);
  void setDuracion(long);
};
