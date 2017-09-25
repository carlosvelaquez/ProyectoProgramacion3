#pragma once
#include "Sprite.h"
#include "Proyectil.h"
#include <thread>
#include <vector>

using namespace std;

class Ataque {
  private:
    int cantidadProyectiles;
    int** posiciones;
    int** velocidades;

    Sprite* decoraciones =  NULL;
    int ** posicionesDecoraciones =  NULL;
    bool aleatorio;
    Sprite spriteProyectiles;

    long vidaProyectiles;
    long duracion;
    long sleepProyectiles;
    long sleepRondas;
    long sleepInicial;

    int anchuraTablero;
    int alturaTablero;

  public:
    Ataque(int nCantidadProyectiles, int * * nPosiciones, int * * nVelocidades, bool nAleatorio, Sprite nSpriteProyectiles, long nVidaProyectiles, long nDuracion, long nSleepProyectiles, long nSleepRondas, long nSleepInicial, int nAnchura, int nAltura);
    vector<Proyectil*>* proyectilesActivos;

    bool activo;

    int getCantidadProyectiles();
    int** getPosiciones();
    int** getVelocidades();
    int** getPosicionesDecoraciones();
    bool isAleatorio();

    Sprite* getDecoraciones();
    Sprite getSpriteProyectiles();

    long getVidaProyectiles();
    long getDuracion();
    long getSleepProyectiles();
    long getSleepRondas();
    long getSleepInicial();

    void setCantidadProyectiles(int nCantidadProyectiles);
    void setPosiciones(int** nPosiciones);
    void setVelocidades(int** nVelocidades);
    void setDecoraciones(Sprite* nDecoraciones);
    void setPosicionesDecoraciones(int** nPosicionesDecoraciones);
    void setAleatorio(bool nAleatorio);
    void setSpriteProyectiles(Sprite nSpriteProyectiles);
    void setVidaProyectiles(long nVidaProyectiles);
    void setDuracion(long nDuracion);
    void setSleepProyectiles(long nSleepProyectiles);
    void setSleepRondas(long nSleepRondas);
    void setSleepInicial(long nSleepInicial);

    void activar();
    void ejecutar();
    void cronometro();
    void interrumpir();

    int getAnchuraTablero();
    int getAlturaTablero();

    void setAnchuraTablero(int nAnchura);
    void setAlturaTablero(int nAltura);

    ~Ataque();
};
