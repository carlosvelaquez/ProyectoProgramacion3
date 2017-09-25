
#include "Proyectil.h"

Proyectil::Proyectil(Sprite nSprite, int posX, int posY, int velX, int velY, long vid){
  sprite = nSprite;
  posicionX = posX;
  posicionY = posY;
  velocidadX = velX;
  velocidadY = velY;
  anchura = 10;
  altura = 10;
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

Sprite Proyectil::getSprite() {
  return sprite;
}

//int getAnchura();
//int getAltura();
int Proyectil::getVelocidadX() {
  return velocidadX;
}

int Proyectil::getVelocidadY() {
  return velocidadY;
}

//int getPosicionX();
//int getPosicionY();
void Proyectil::setSprite(Sprite nSprite) {
  sprite = nSprite;
}

void Proyectil::setVelocidadX(int velX) {
  velocidadX = velX;
}

void Proyectil::setVelocidadY(int velY) {
  velocidadY = velY;
}

//void setPosicionX(int);
//void setPosicionY(int);
void Proyectil::activar() {
  activo = true;
  thread ejecucion (&Proyectil::ejecutar, this);
  ejecucion.detach();
}

void Proyectil::ejecutar() {
  visible = true;

  for (int i = 0; i < vida/50; i++) {
    posicionX += velocidadX;
    posicionY += velocidadY;
    this_thread::sleep_for(chrono::milliseconds(50));
  }

  visible = false;
}

SDL_Surface * Proyectil::toSuperficie() {
  if (!visible) {
    return NULL;
  }

  return sprite.toSuperficie();
}

bool Proyectil::refrescar() {
  return true;
}

