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
  double flinch;
  double velocidadFlinch;

public:
  int getAtaque();
  int getDefensa();
  int getHP();
  string getNombre();
  Sprite getSprite();
  Sonido getSonidoDialogo();
  Ataque* getAtaques();
  int getCantidadAtaques();
  Texto* getDialogo();
  double getFlinch();
  double getVelocidadFlinch();

  void setAtaque(int);
  void setDefensa(int);
  void setHP(int);
  void setNombre(string);
  void setSprite(Sprite);
  void setSonidoDialogo(Sonido);
  void setAtaques(Ataque*, int);
  void setAtaques(Ataque*);
  void setDialogo(Texto*);
  void setFlinch(double);
  void setVelocidadFlinch(double);
};
