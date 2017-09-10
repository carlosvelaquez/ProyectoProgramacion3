#pragma once
#include "Imagen.h"
#include "HUD.h"
#include "Espacio.h"

class Escenario{
private:
  Imagen fondo;
  HUD* hud;
  int tipo;
  Espacio* espacio;

public:
  Escenario();

  Imagen getFondo();
  HUD* getHUD();
  int getTipo();
  Espacio* getEspacio();

  void setFondo(Imagen);
  void setHUD(HUD*);
  void setTipo(int);
  void setEspacio(Espacio*);

  ~Escenario();
};
