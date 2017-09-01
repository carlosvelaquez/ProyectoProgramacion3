#pragma once
#include <vector>
#include "Prop.h"

class Espacio{
private:
  Prop** espacio;
  int altura;
  int anchura;
public:
  Prop** getEspacio();
  int getAltura();
  int getAnchura();

  void setEspacio(Prop**);
  void setAltura(int);
  void setAnchura(int);
};
