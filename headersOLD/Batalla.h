#ifndef _BATALLA_H
#define _BATALLA_H


#include "Imagen.h"

class Enemigo;
class Musica;
class Sprite;

class Batalla {
  private:
    Enemigo * enemigo;

    Imagen fondo;

    Musica * musica;

    Sprite * decoraciones;

    bool activa;

    int turno;


  public:
    Batalla(Enemigo * nEnemigo, Imagen nFondo, Musica * nMusica, Sprite * nDecoraciones);

    Enemigo * getEnemigo();

    Imagen getFondo();

    Musica * getMusica();

    Sprite * getDecoraciones();

    bool isActiva();

    void setEnemigo(Enemigo * nEnemigo);

    void setFondo(Imagen );

    void setMusica(Musica * nMusica);

    void setDecoraciones(Sprite * nDeco);

    void setActiva(bool nActiva);

    ~Batalla();

};
#endif
