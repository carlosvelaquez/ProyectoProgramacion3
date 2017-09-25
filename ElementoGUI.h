#pragma once
#include "SDL/SDL.h"
#include "Imagen.h"

class ElementoGUI {
  protected:
    int anchura=  0;
    int altura=  0;
    int posicionX=  0;
    int posicionY=  0;

    bool visible;


  public:
    int getAnchura();
    int getAltura();
    int getPosicionX();
    int getPosicionY();

    void setAnchura(int nAnchura);
    void setAltura(int nAltura);
    void setPosicionX(int posX);
    void setPosicionY(int posY);

    virtual void centrar();
    virtual void setVisible(bool nVisible);
    virtual bool isVisible();
    virtual SDL_Surface * toSuperficie() = 0;
    virtual bool refrescar() = 0;
};
