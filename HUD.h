#pragma once
#include "ElementoGUI.h"
#include <vector>

using namespace std;

class HUD{
private:
  vector<ElementoGUI> elementos;
public:
  HUD();
  HUD(vector<ElementoGUI>);
  addElemento(ElementoGUI*);
  removeElemento(ElementoGUI*);
  removeElemento(int);
}
