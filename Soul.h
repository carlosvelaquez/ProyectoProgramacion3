#pragma once
#include "ElementoGUI.h"
#include "Sprite.h"
#include <vector>
#include <thread>

class Soul : public ElementoGUI {
  private:
    Sprite sprite;

    int velocidad;
    int velocidadBlink;
    long duracionBlink;

    bool visible;
    bool salirTrap;

    int hp;
    SDL_Rect bounds;


  public:
    Soul();

    Sprite getSprite();
    int getVelocidad();
    int getVelocidadBlink();
    long getDuracionBlink();
    int getHP();

    void setSprite(Sprite nSprite);
    void setVelocidad(int nVelocidad);
    void setVelocidadBlink(int );
    void setDuracionBlink(long );
    void setHP(int nHP);

    void trap();
    void blink();
    void comenzarBlink();
    void mover(int direccion);
    void terminarTrap();
    void centrar();

    SDL_Rect getBounds();
    void setBounds(SDL_Rect nBounds);
    SDL_Surface* toSuperficie();
    bool refrescar();

};
