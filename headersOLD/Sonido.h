#ifndef _SONIDO_H
#define _SONIDO_H


#include "Audio.h"
#include <string>
using namespace std;

class Sonido : public Audio {
  private:
    Mix_Chunk * sonido;


  public:
    Sonido();

    Sonido(string nRuta);

    bool reproducir();

    bool cargar();

    bool parar();

    bool verificar();

    string identificar();

    void liberar();

    ~Sonido();

};
#endif
