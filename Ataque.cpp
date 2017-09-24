#include "Ataque.h"

Ataque::Ataque(int nCantidadProyectiles, int** nPosiciones, int** nVelocidades, bool nAleatorio, Sprite nSpriteProyectiles, long nVidaProyectiles, long nDuracion, long nSleepProyectiles, long nSleepRondas, long nSleepInicial, int nAnchura, int nAltura){
  cantidadProyectiles = nCantidadProyectiles;
  posiciones = nPosiciones;
  velocidades = nVelocidades;
  aleatorio = nAleatorio;
  spriteProyectiles = nSpriteProyectiles;
  vidaProyectiles = nVidaProyectiles;
  sleepProyectiles = nSleepProyectiles;
  sleepRondas = nSleepRondas;
  sleepInicial = nSleepInicial;
  duracion = nDuracion;
  anchuraTablero = nAnchura;
  alturaTablero = nAltura;
}

int Ataque::getCantidadProyectiles(){
  return cantidadProyectiles;
}

int** Ataque::getPosiciones(){
  return posiciones;
}

int** Ataque::getVelocidades(){
  return velocidades;
}

int** Ataque::getPosicionesDecoraciones(){
  return posicionesDecoraciones;
}

bool Ataque::isAleatorio(){
  return aleatorio;
}

Sprite* Ataque::getDecoraciones(){
  return decoraciones;
}

long Ataque::getVidaProyectiles(){
  return vidaProyectiles;
}

long Ataque::getDuracion(){
  return duracion;
}

long Ataque::getSleepProyectiles(){
  return sleepProyectiles;
}

long Ataque::getSleepRondas(){
  return sleepProyectiles;
}

long Ataque::getSleepInicial(){
  return sleepInicial;
}

void Ataque::setCantidadProyectiles(int nCantidadProyectiles){
  cantidadProyectiles = nCantidadProyectiles;
}

void Ataque::setPosiciones(int** nPosiciones){
  posiciones = nPosiciones;
}
void Ataque::setVelocidades(int** nVelocidades){
  velocidades = nVelocidades;
}

void Ataque::setDecoraciones(Sprite* nDecoraciones){
  decoraciones = nDecoraciones;
}

void Ataque::setPosicionesDecoraciones(int** nPosicionesDecoraciones){
  posicionesDecoraciones = nPosicionesDecoraciones;
}

void Ataque::setAleatorio(bool nAleatorio){
  aleatorio = nAleatorio;
}

void Ataque::setSpriteProyectiles(Sprite nSpriteProyectiles){
  spriteProyectiles = nSpriteProyectiles;
}

void Ataque::setVidaProyectiles(long nVidaProyectiles){
  vidaProyectiles = nVidaProyectiles;
}

void Ataque::setDuracion(long nDuracion){
  duracion = nDuracion;
}

void Ataque::setSleepProyectiles(long nSleepProyectiles){
  sleepProyectiles = nSleepProyectiles;
}

void Ataque::setSleepRondas(long nSleepRondas){
  sleepRondas = nSleepRondas;
}

void Ataque::setSleepInicial(long nSleepInicial){
  sleepInicial = nSleepInicial;
}

void Ataque::activar(){
  activo = true;
  thread ejecucion (&Ataque::ejecutar, this);
  ejecucion.detach();
}

void Ataque::ejecutar(){
  int cont = 0;
  int* contador = &cont;

  thread cronom (&Ataque::cronometro, this, contador);

  while (*contador < duracion) {
    for (int i = 0; i < cantidadProyectiles; i++) {
      int posX, posY, velX, velY;
      posX = posiciones[i][0];
      posY = posiciones[i][1];
      velX = velocidades[i][0];
      velY = velocidades[i][1];

      Proyectil p(spriteProyectiles, posX, posY, velX, velY, vidaProyectiles);
      proyectilesActivos.push_back(p);
      proyectilesActivos.at(proyectilesActivos.size() - 1).activar();
      this_thread::sleep_for(chrono::milliseconds(sleepProyectiles));
    }
    this_thread::sleep_for(chrono::milliseconds(sleepRondas));
  }

  cronom.join();
  proyectilesActivos.clear();
  delete contador;
  activo = false;
}

void Ataque::cronometro(int* tiempo){
  while (*tiempo < duracion) {
    *tiempo ++;
    this_thread::sleep_for(chrono::milliseconds(1));
  }
}

int Ataque::getAnchuraTablero(){
  return anchuraTablero;
}

int Ataque::getAlturaTablero(){
  return alturaTablero;
}


void Ataque::setAnchuraTablero(int nAnchura){
  anchuraTablero = nAnchura;
}

void Ataque::setAlturaTablero(int nAltura){
  alturaTablero = nAltura;
}


Ataque::~Ataque(){
  /*for (int i = 0; i < cantidadProyectiles; i++) {
    delete[] posiciones;
    delete[] velocidades;
  }

  delete decoraciones;*/
}
