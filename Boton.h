#pragma once
#include "ElementoGUI.h"

class Boton : public ElementoGUI{
private:
  bool seleccionado;
public:
  bool isSeleccionado();
  void setSeleccionado();
};
