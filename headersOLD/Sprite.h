#ifndef _SPRITE_H
#define _SPRITE_H


#include "Imagen.h"
#include <string>
using namespace std;

class Sprite {
  private:
    Imagen fuente;

    SDL_Rect * clip=  NULL;

    SDL_Surface * superficie=  NULL;


  public:
    Sprite();

    Sprite(string nImagenFuente);

    Sprite(Imagen nFuente);

    Sprite(Imagen nFuente, SDL_Rect * nClip);

    Imagen getFuente();

    SDL_Rect * getClip();

    void setFuente(Imagen nFuente);

    void setClip(SDL_Rect * nClip);

    void setClip(int x, int y);

    SDL_Surface * toSuperficie();

    //bool refrescar();
    ~Sprite();

};
#endif
