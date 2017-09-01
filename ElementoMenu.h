#pragma once
#include "ElementoGUI.h"

class ElementoMenu : public ElementoGUI{
private:
  Texto texto;
  bool seleccionado;
public:
  Texto getTexto();
  bool getSeleccionado();

  void setTexto(Texto);
  void setSeleccionado(bool);
};
