#include "AtaqueJugador.h"

AtaqueJugador::AtaqueJugador(Sonido* nSonido, vector<Sprite> nFrames, long nVelocidad){
  sonido = nSonido;
  frames = nFrames;
  velocidad = nVelocidad;
  indiceActual = 0;
}

Sonido* AtaqueJugador::getSonido(){
  return sonido;
}

vector<Sprite> AtaqueJugador::getFrames(){
  return frames;
}

long AtaqueJugador::getVelocidad(){
  return velocidad;
}

int AtaqueJugador::getIndiceActual(){
  return indiceActual;
}

void AtaqueJugador::setSonido(Sonido* nSonido){
  sonido = nSonido;
}

void AtaqueJugador::setFrames(vector<Sprite> nFrames){
  frames = nFrames;
}

void AtaqueJugador::setVelocidad(long nVelocidad){
  velocidad = nVelocidad;
}

void AtaqueJugador::setIndiceActual(int nIndice){
  indiceActual = nIndice;
}

SDL_Surface* AtaqueJugador::toSuperficie(){
  return (frames[indiceActual].toSuperficie());
}

bool AtaqueJugador::refrescar(){
  std::cout << "[ATAQUEJUGADOR] Refrescando. Indice Actual: " << indiceActual << '\n';
}

AtaqueJugador::~AtaqueJugador(){
  delete sonido;
}
