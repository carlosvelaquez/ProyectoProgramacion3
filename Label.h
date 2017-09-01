#pragma once
#include "ElementoGUI.h"

class Label : public ElementoGUI{
private:
  Texto texto;
public:
  Texto getTexto();
  void setTexto();
};
