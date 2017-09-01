#pragma once
#include "Boton.h"

class BotonAccion : public Boton{
private:
  Color color;
  Texto texto;
  Icono icono;
  Color colorSeleccionado;
  Icono iconoSeleccionado;
public:
  Color getColor();
  Texto getTexto();
  Icono getIcono();
  Color getColorSeleccionado();
  Icono getIconoSeleccionado();

  void setColor(Color);
  void setTexto(Texto);
  void setIcono(Icono);
  void setColorSeleccionado(Color);
  void setIconoSeleccionado(Icono);
};
