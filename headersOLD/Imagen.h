#ifndef _IMAGEN_H
#define _IMAGEN_H


#include <string>
using namespace std;

class Imagen {
  private:
    string ruta;

    SDL_Surface * superficie=  NULL;

    bool cargada=  false;

    int anchura;

    int altura;


  public:
    Imagen();

    Imagen(string nRuta);

    string getRuta();

    SDL_Surface * getSuperficie();

    void setRuta(string );

    bool recargar();

    int getAnchura();

    int getAltura();

    virtual SDL_Surface * toSuperficie();

    ~Imagen();

};
#endif
