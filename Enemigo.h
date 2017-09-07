#pragma once
#include <string>
#include "Sprite.h"
#include "Sonido.h"
#include "Ataque.h"

using namespace std;

class Enemigo{
private:
  int ataque;
  int defensa;
  int hp;
  string nombre;
  Sprite sprite;
  Sonido sonidoDialogo;
  Ataque* ataques;
  int cantidadAtaques;
  Texto* dialogo;
  int flinch;
  int velocidadFlinch;

public:
  Enemigo(int, int, int, string, Sprite, Sonido, Ataque*, int, Texto*, int, int);

  int getAtaque();
  int getDefensa();
  int getHP();
  string getNombre();
  Sprite getSprite();
  Sonido getSonidoDialogo();
  Ataque* getAtaques();
  int getCantidadAtaques();
  Texto* getDialogo();
  int getFlinch();
  int getVelocidadFlinch();

  void setAtaque(int);
  void setDefensa(int);
  void setHP(int);
  void setNombre(string);
  void setSprite(Sprite);
  void setSonidoDialogo(Sonido);
  void setAtaques(Ataque*, int);
  void setAtaques(Ataque*);
  void setDialogo(Texto*);
  void setFlinch(int);
  void setVelocidadFlinch(int);

  ~Enemigo();
};
