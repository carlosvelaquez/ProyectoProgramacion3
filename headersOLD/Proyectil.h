#ifndef _PROYECTIL_H
#define _PROYECTIL_H


#include "ElementoGUI.h"
#include "Sprite.h"

class Proyectil : public ElementoGUI {
  private:
    Sprite sprite;

    //int anchura;
    //int altura;
    
    int velocidadX;

    int velocidadY;

    //int posicionX;
    //int posicionY;
    
    long vida;

    bool activo=  false;


  public:
    Proyectil(Sprite nSprite, int posX, int posY, int velX, int velY, long vid);

    Proyectil(Sprite nSprite, int posX, int posY);

    Sprite getSprite();

    //int getAnchura();
    //int getAltura();
    int getVelocidadX();

    int getVelocidadY();

    //int getPosicionX();
    //int getPosicionY();
    void setSprite(Sprite nSprite);

    void setVelocidadX(int velX);

    void setVelocidadY(int velY);

    //void setPosicionX(int);
    //void setPosicionY(int);
    void activar();

    void ejecutar();

    SDL_Surface * toSuperficie();

    bool refrescar();

};
#endif
