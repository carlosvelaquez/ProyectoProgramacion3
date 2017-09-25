#ifndef _ENEMIGO_H
#define _ENEMIGO_H


#include <string>
using namespace std;
#include "Sprite.h"
#include "Sonido.h"
#include <vector>
using namespace std;

class Ataque;

class Enemigo {
  private:
    int ataque;

    int defensa;

    int hp;

    string nombre;

    Sprite sprite;

    Sonido sonidoDialogo;

    vector<Ataque> ataques;

    int cantidadAtaques;

    vector<string> dialogo;

    int flinch;

    int velocidadFlinch;

    int limiteAtaques;


  public:
    Enemigo(int nAtaque, int nDefensa, int nHP, string nNombre, Sprite nSprite, Sonido nSonidoDialogo, vector<Ataque> nAtaques, int nCantidadAtaques, vector<string> nDialogo, int nFlinch, int nVelocidadFlinch);

    int getAtaque();

    int getDefensa();

    int getHP();

    string getNombre();

    Sprite getSprite();

    Sonido getSonidoDialogo();

    vector<Ataque> getAtaques();

    int getCantidadAtaques();

    vector<string> getDialogo();

    int getFlinch();

    int getVelocidadFlinch();

    int getLimiteAtaques();

    void setAtaque(int nAtaque);

    void setDefensa(int nDefensa);

    void setHP(int nHP);

    void setNombre(string nNombre);

    void setSprite(Sprite nSprite);

    void setSonidoDialogo(Sonido nSonidoDialogo);

    void setAtaques(vector<Ataque> nAtaques);

    void setDialogo(vector<string> nDialogo);

    void setFlinch(int nFlinch);

    void setVelocidadFlinch(int nVelocidadFlinch);

    void setLimiteAtaques(int );

    //SDL_Surface* toSuperficie();
    //bool refrescar();
    ~Enemigo();

};
#endif
