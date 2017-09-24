#include "Sprite.h"

Sprite::Sprite(){
  Imagen nFuente("./assets/souls.png");
  fuente = nFuente;
  //altura = fuente.getAltura();
  //anchura = fuente.getAnchura();
}

Sprite::Sprite(string nImagenFuente){
  Imagen nFuente(nImagenFuente);
  fuente = nFuente;
  //altura = fuente.getAltura();
  //anchura = fuente.getAnchura();
}

Sprite::Sprite(Imagen nFuente){
  fuente = nFuente;
  //altura = fuente.getAltura();
  //anchura = fuente.getAnchura();
}

Sprite::Sprite(Imagen nFuente, SDL_Rect* nClip){
  fuente = nFuente;
  clip = nClip;
}

Imagen Sprite::getFuente(){
  return fuente;
}

SDL_Rect* Sprite::getClip(){
  return clip;
}

void Sprite::setFuente(Imagen nFuente){
  fuente = nFuente;
}

void Sprite::setClip(SDL_Rect* nClip){
  clip = nClip;
}

void Sprite::setClip(int x, int y){
  SDL_Rect nClip;
  nClip.x = x;
  nClip.y = y;

  clip = &nClip;
}

SDL_Surface* Sprite::toSuperficie(){
  return fuente.toSuperficie();
}

/*bool Sprite::refrescar(){
  fuente.recargar();
}*/

Sprite::~Sprite(){
  //delete clip;
  //delete superficie;
}
