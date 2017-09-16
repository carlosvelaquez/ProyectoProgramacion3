#pragma once
#include "ElementoGUI.h"
#include <vector>

using namespace std;

class HUD{
private:
  vector<ElementoGUI*> elementos;
public:
  HUD();
  HUD(vector<ElementoGUI*>);
  void addElemento(ElementoGUI*);

  vector<ElementoGUI*> getElementos();
  void setElementos(vector<ElementoGUI*>);
  //void removeElemento(ElementoGUI*);
  //void removeElemento(int);
};
