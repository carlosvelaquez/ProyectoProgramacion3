#include "Prop.h"

Prop::Prop(int nAltura, int nAnchura, int posX, int posY, Sprite nSprite, bool nSolido){
  altura = nAltura;
  anchura = nAnchura;
  posicionX = posX;
  posicionY = posY;
  sprite = nSprite;
  solido = nSolido;
}

int Prop::getAltura(){
  return altura;
}

int Prop::getAnchura(){
  return anchura;
}

int Prop::getPosicionX(){
  return posicionX;
}

int Prop::getPosicionY(){
  return posicionY;
}

Sprite Prop::getSprite(){
  return sprite;
}

bool Prop::isSolido(){
  return solido;
}

void Prop::setAltura(int nAltura){
  altura = nAltura;
}

void Prop::setAnchura(int nAnchura){
  anchura = nAnchura;
}

void Prop::setPosicionX(int posX){
  posicionX = posX;
}

void Prop::setPosicionY(int posY){
  posicionY = posY;
}

void Prop::setSprite(Sprite nSprite){
  sprite = nSprite;
}

void Prop::setSolido(bool nSolido){
  solido = nSolido;
}
