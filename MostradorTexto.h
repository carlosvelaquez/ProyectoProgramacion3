#pragma once
#include "ElementoGUI.h"
#include "Texto.h"

class MostradorTexto : public ElementoGUI{
private:
  Texto texto;
  Sonido sonido;
  int velocidad;
public:
  Texto getTexto();
  Sonido getSonido;
  int getVelocidad();

  void setTexto(Texto*);
  void setSonido(Sonido*);
  void setVelocidad(int);
};
