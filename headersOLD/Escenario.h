#ifndef _ESCENARIO_H
#define _ESCENARIO_H


#include "Imagen.h"

class HUD;
class Espacio;

class Escenario {
  private:
    Imagen fondo;

    HUD * hud;

    int tipo;

    Espacio * espacio;


  public:
    Escenario();

    Imagen getFondo();

    HUD * getHUD();

    int getTipo();

    Espacio * getEspacio();

    void setFondo(Imagen nFondo);

    void setHUD(HUD * nHud);

    void setTipo(int );

    void setEspacio(Espacio * nEspacio);

    ~Escenario();

};
#endif
