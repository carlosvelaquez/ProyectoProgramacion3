#pragma once
#include <vector>
#include "ElementoGUI.h"
#include "Soul.h"
#include "Proyectil.h"

class Tablero : public ElementoGUI{
private:
  int modo;
  vector<Proyectil> proyectiles;
  Soul soul;
public:
  int getModo();
  vector<Proyectil> getProyectiles();
  Soul getSoul();

  void setModo(int);
  void setProyectiles(vector<Proyectil>);
  void setSoul(Soul);
};
