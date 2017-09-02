#include "Ataque.h"

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

Proyectil Ataque::getProyectil(){
  return Proyectil;
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

void Ataque::setProyectil(Proyectil nProyectil){
  proyectil = nProyectil;
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
