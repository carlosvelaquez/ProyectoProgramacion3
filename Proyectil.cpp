#include "Proyectil.h"

Proyectil::Proyectil(Sprite nSprite, int posX, int posY, int velX, int velY, long vid){
  sprite = nSprite;
  posicionX = posX;
  posicionY = posY;
  velocidadX = velX;
  velocidadY = velY;
  vida = vid;
}

Proyectil::Proyectil(Sprite nSprite, int posX, int posY){
  sprite = nSprite;
  posicionX = posX;
  posicionY = posY;
  velocidadX = 0;
  velocidadY = 0;
  vida = 1000;
}

Sprite Proyectil::getSprite(){
  return sprite;
}

/*int Proyectil::getAnchura(){
  return anchura;
}

int Proyectil::getAltura(){
  return altura;
}*/

int Proyectil::getVelocidadX(){
  return velocidadX;
}

int Proyectil::getVelocidadY(){
  return velocidadY;
}

/*int Proyectil::getPosicionX(){
  return posicionX;
}

int Proyectil::getPosicionY(){
  return posicionY;
}*/

void Proyectil::setSprite(Sprite nSprite){
  sprite = nSprite;
}

/*void Proyectil::setPosicionX(int posX){
  posicionX = posX;
}

void Proyectil::setPosicionY(int posY){
  posicionY = posY;
}*/

void Proyectil::setVelocidadX(int velX){
  velocidadX = velX;
}

void Proyectil::setVelocidadY(int velY){
  velocidadY = velY;
}

void Proyectil::activar(){
  activo = true;
  thread ejecucion (&Proyectil::ejecutar, this);
  ejecucion.detach();
}

void Proyectil::ejecutar(){
  for (int i = 0; i < vida; i++) {
    posicionX += velocidadX;
    posicionY += velocidadY;
    this_thread::sleep_for(chrono::milliseconds(1));
  }
}

SDL_Surface* Proyectil::toSuperficie(){
  return sprite.toSuperficie();
}

bool Proyectil::refrescar(){
  return true;
}
