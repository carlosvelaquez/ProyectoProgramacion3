#pragma once
#include <string>
#include <vector>
#include "Sprite.h"
#include "Sonido.h"
#include "Ataque.h"
#include "Texto.h"
#include "ElementoGUI.h"

using namespace std;

class Enemigo{
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
  Enemigo(int, int, int, string, Sprite, Sonido, vector<Ataque>, int, vector<string>, int, int);

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

  void setAtaque(int);
  void setDefensa(int);
  void setHP(int);
  void setNombre(string);
  void setSprite(Sprite);
  void setSonidoDialogo(Sonido);
  void setAtaques(vector<Ataque>);
  void setDialogo(vector<string>);
  void setFlinch(int);
  void setVelocidadFlinch(int);
  void setLimiteAtaques(int);

  //SDL_Surface* toSuperficie();
  //bool refrescar();

  ~Enemigo();
};
