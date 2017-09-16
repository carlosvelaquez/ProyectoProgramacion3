#pragma once
#include "Sprite.h"
#include "Proyectil.h"
#include <thread>
#include <vector>

using namespace std;

class Ataque{
private:
  int cantidadProyectiles;
  int** posiciones;
  int** velocidades;
  Sprite* decoraciones = NULL;
  int** posicionesDecoraciones = NULL;
  bool aleatorio;
  Sprite spriteProyectiles;
  long vidaProyectiles;
  long duracion;
  long sleepProyectiles;
  long sleepRondas;
  long sleepInicial;
  bool activo;

  int anchuraTablero;
  int alturaTablero;

public:
  Ataque(int, int**, int**, bool, Sprite, long, long, long, long, long, int, int);

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

  void setCantidadProyectiles(int);
  void setPosiciones(int**);
  void setVelocidades(int**);
  void setDecoraciones(Sprite*);
  void setPosicionesDecoraciones(int**);
  void setAleatorio(bool);
  void setSpriteProyectiles(Sprite);
  void setVidaProyectiles(long);
  void setDuracion(long);
  void setSleepProyectiles(long);
  void setSleepRondas(long);
  void setSleepInicial(long);

  void activar();
  void ejecutar();
  void cronometro(int*);

  int getAnchuraTablero();
  int getAlturaTablero();

  void setAnchuraTablero(int);
  void setAlturaTablero(int);
  vector<Proyectil> proyectilesActivos;

  ~Ataque();
};
