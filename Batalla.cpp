#include "Batalla.h"

Batalla::Batalla(Enemigo nEnemigo, Imagen nFondo, Sonido nMusica, Sprite* nDecoraciones){
  enemigo = nEnemigo;
  fondo = nFondo;
  musica = nMusica;
  decoraciones = nDecoraciones;
}

Batalla::~Batalla(){
  delete decoraciones;
}

Enemigo Batalla::getEnemigo(){
  return enemigo;
}

Imagen Batalla::getFondo(){
  return fondo;
}

Sonido Batalla::getMusica(){
  return musica;
}

Sprite* Batalla::getDecoraciones(){
  return decoraciones;
}

bool Batalla::isActiva(){
  return activa;
}

void Batalla::setEnemigo(Enemigo nEnemigo){
  enemigo = nEnemigo;
}

void Batalla::setMusica(Sonido nMusica){
  musica = nMusica;
}

void Batalla::setDecoraciones(bool nActiva){
  activa = nActiva;
}

Batalla::~Batalla(){
  delete decoraciones;
}
