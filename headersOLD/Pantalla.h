#ifndef _PANTALLA_H
#define _PANTALLA_H


class Escenario;

class Pantalla {
  private:
    Escenario * escenario;

    int altura;

    int anchura;

    SDL_Surface * superficie=  NULL;


  public:
    Pantalla(int nAltura, int nAnchura);

    Escenario * getEscenario();

    int getAltura();

    int getAnchura();

    void setEscenario(Escenario * nEscenario);

    void setAltura(int nAltura);

    void setAnchura(int nAnchura);

    bool refrescar();

    bool limpiar();

    void aplicarSuperficie(SDL_Surface * sup, int x, int y);

    void fade(int tipo, long duracion);

    ~Pantalla();

};
#endif
