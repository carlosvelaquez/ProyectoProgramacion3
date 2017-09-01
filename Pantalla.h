#pragma once
#include "Escenario.h"

class Pantalla{
private:
  Escenario escenario;
  int altura;
  int anchura;
public:
  bool refrescar();
  bool limpiar();

  Escenario getEscenario();
  int getAltura();
  int getAnchura();

  void setEscenario(Escenario);
  void setAltura(int);
  void setAnchura(int);
};
