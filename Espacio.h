#pragma once
#include <vector>
#include "Prop.h"

class Espacio{
private:
  vector<Prop> props;
  int altura;
  int anchura;

public:
  Espacio(int, int);
  Espacio(int, int, vector<Prop>);

  vector<Prop> getProps();
  int getAltura();
  int getAnchura();

  void setProps(vector<Prop>);
  void setAltura(int);
  void setAnchura(int);

  void addProp(Prop);
};
