#ifndef _BARRAPROGRESO_H
#define _BARRAPROGRESO_H


#include "ElementoGUI.h"

class BarraProgreso : public ElementoGUI {
  private:
    Uint32 colorFondo;

    Uint32 colorProgreso;

    float porcentaje;

    float porcentajeMax;

    bool visible;


  public:
    BarraProgreso();

    BarraProgreso(float nPorcentaje, float nPorcentajeMax);

    BarraProgreso(float nPorcentaje, float nPorcentajeMax, Uint32 nFondo, Uint32 nProgreso);

    Uint32 getColorFondo();

    Uint32 getColorProgreso();

    float getPorcentaje();

    float getPorcentajeMax();

    bool isVisible();

    void setColorFondo(Uint32 nFondo);

    void setColorProgreso(Uint32 nProgreso);

    void setPorcentaje(float nPorcentaje);

    void setPorcentajeMax(float nPorcentajeMax);

    void setVisible(bool nVisible);

    SDL_Surface * toSuperficie();

    bool refrescar();

};
#endif
