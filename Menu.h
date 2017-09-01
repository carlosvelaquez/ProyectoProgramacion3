#pragma once
#include "ElementoGUI.h"

class Menu : public ElementoGUI{
private:
  vector<ElementoMenu> elementos;
  bool activo;
public:
  vector<ElementoMenu> getElementos();
  bool isActivo();
  void setElementos(vector<ElementoMenu>);
  void setActivo(bool);
};
