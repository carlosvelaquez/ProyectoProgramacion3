
#include "Batalla.h"
#include "Enemigo.h"
#include "Musica.h"
#include "Sprite.h"

Batalla::Batalla(Enemigo * nEnemigo, Imagen nFondo, Musica * nMusica, Sprite * nDecoraciones){
  enemigo = nEnemigo;
  fondo = nFondo;
  musica = nMusica;
  decoraciones = nDecoraciones;
}

Enemigo * Batalla::getEnemigo() {
  return enemigo;
}

Imagen Batalla::getFondo() {
  return fondo;
}

Musica * Batalla::getMusica() {
  return musica;
}

Sprite * Batalla::getDecoraciones() {
  return decoraciones;
}

bool Batalla::isActiva() {
  return activa;
}

void Batalla::setEnemigo(Enemigo * nEnemigo) {
  enemigo = nEnemigo;
}

void Batalla::setFondo(Imagen ) {
}

void Batalla::setMusica(Musica * nMusica) {
  musica = nMusica;
}

void Batalla::setDecoraciones(Sprite * nDeco) {
  decoraciones = nDeco;
}

void Batalla::setActiva(bool nActiva) {
  activa = nActiva;
}

Batalla::~Batalla(){
  if (decoraciones != NULL) {
    delete decoraciones;
  }
}

