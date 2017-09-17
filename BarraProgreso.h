#pragma once
#include "ElementoGUI.h"

class BarraProgreso : public ElementoGUI{
private:
  Uint32 colorFondo;
  Uint32 colorProgreso;
  float porcentaje;
  float porcentajeMax;
  bool visible;

public:
  BarraProgreso();
  BarraProgreso(float, float);
  BarraProgreso(float, float, Uint32, Uint32);

  Uint32 getColorFondo();
  Uint32 getColorProgreso();
  float getPorcentaje();
  float getPorcentajeMax();
  bool isVisible();

  void setColorFondo(Uint32);
  void setColorProgreso(Uint32);
  void setPorcentaje(float);
  void setPorcentajeMax(float);
  void setVisible(bool);

  SDL_Surface* toSuperficie();
  bool refrescar();
};
