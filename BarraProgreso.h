#pragma once
#include "ElementoGUI.h"

class BarraProgreso : public ElementoGUI{
private:
  Color colorFondo;
  Color colorProgreso;
  float porcentaje;
  float porcentajeMax;
public:
  Color getColorFondo();
  Color getColorProgreso();
  float getPorcentaje();
  float getPorcentajeMax();

  void setColorFondo(Color);
  void setColorProgreso(Color);
  void setPorcentaje(float);
  void setPorcentajeMax(float);
};
