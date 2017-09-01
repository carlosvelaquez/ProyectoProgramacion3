#pragma once
#include "Imagen.h"
#include "HUD.h"
#include "Espacio.h"

class Escenario{
private:
  Imagen fondo;
  HUD hud;
  int tipo;
  Espacio* espacio = NULL;
public:
  Imagen getFondo();
  HUD getHUD();
  int getTipo();
  Espacio getEspacio();

  void setFondo(Image);
  void setHUD(HUD);
  void setTipo(int);
  void setEspacio(Espacio*);
};
