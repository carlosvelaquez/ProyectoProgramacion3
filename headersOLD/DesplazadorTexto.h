#ifndef _DESPLAZADORTEXTO_H
#define _DESPLAZADORTEXTO_H


#include "ElementoGUI.h"
#include "Texto.h"

class Sonido;

class DesplazadorTexto : public ElementoGUI {
  private:
    Texto texto;

    Sonido * sonido;

    long velocidad;

    bool activo;

    bool visible;

    bool mute=  false;


  public:
    DesplazadorTexto(Texto nTexto, Sonido * nSonido, long nVelocidad);

    Texto getTexto();

    Sonido * getSonido();

    long getVelocidad();

    bool isActivo();

    bool isVisible();

    bool isMuted();

    void setTexto(Texto nTexto);

    void setSonido(Sonido * nSonido);

    void setVelocidad(long nVelocidad);

    void setVisible(bool nVisible);

    void setMute(bool nMute);

    void iniciar();

    void desplazar();

    SDL_Surface * toSuperficie();

    bool refrescar();

};
#endif
