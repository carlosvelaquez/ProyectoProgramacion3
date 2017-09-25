#ifndef _MUSICA_H
#define _MUSICA_H


#include "Audio.h"
#include <string>
using namespace std;

class Musica : public Audio {
  private:
    Mix_Music * musica;


  public:
    Musica(string nRuta);

    bool pausar();

    bool resumir();

    bool parar();

    bool reproducir();

    bool cargar();

    bool verificar();

    string identificar();

    void liberar();

    ~Musica();

};
#endif
