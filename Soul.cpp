#include "Soul.h"

Soul::Soul(){
  velocidad = 5;
  velocidadBlink = 150;
  duracionBlink = 1000;
  visible = false;
  sprite = Sprite("./assets/soul.png");
  altura = 16;
  anchura = 16;
}

Sprite Soul::getSprite(){
  return sprite;
}

int Soul::getVelocidad(){
  return velocidad;
}

int Soul::getVelocidadBlink(){
  return velocidadBlink;
}

long Soul::getDuracionBlink(){
  return duracionBlink;
}

void Soul::setSprite(Sprite nSprite){
  sprite = nSprite;
}

void Soul::setVelocidad(int nVelocidad){
  velocidad = nVelocidad;
}

void Soul::trap(){
  SDL_Event ev;
  salirTrap = false;
  visible = true;
  Uint8* tecla = SDL_GetKeyState(NULL);

  while(!salirTrap){
    //delete[] tecla;
    SDL_PumpEvents();
    /*while (SDL_PollEvent(&ev)) {
      //std::cout << "[SOUL] Entrando a trap..." << '\n';
      if (ev.type = SDL_KEYDOWN) {
        switch (ev.key.keysym.sym) {
          case SDLK_UP:{
            mover(1);
            break;
          }
          case SDLK_DOWN:{
            mover(2);
            break;
          }
          case SDLK_LEFT:{
            mover(3);
            break;
          }
          case SDLK_RIGHT:{
            mover(4);
            break;
          }
          case SDLK_0:{
            salir = true;
            break;
          }
          case SDLK_9:{
            blink();
            break;
          }
        }
      }
    }*/

    if (tecla[SDLK_UP]) {
      mover(1);
    }
    if (tecla[SDLK_DOWN]) {
      mover(2);
    }
    if (tecla[SDLK_LEFT]) {
      mover(3);
    }
    if (tecla[SDLK_RIGHT]) {
      mover(4);
    }
    if (tecla[SDLK_0]) {
      salirTrap = true;
    }
    if (tecla[SDLK_9]) {
      blink();
      this_thread::sleep_for(chrono::milliseconds(200));
    }

    if (!salirTrap) {
      this_thread::sleep_for(chrono::milliseconds(30));
    }

  }

  visible = false;
}

void Soul::blink(){
  thread blinker (&Soul::comenzarBlink, this);
  blinker.detach();
}

void Soul::comenzarBlink(){
  visible = false;

  for (size_t i = 0; i < duracionBlink; i++) {
    if (i%velocidadBlink == 0) {
      if (visible) {
        visible = false;
      }else{
        visible = true;
      }
    }
    this_thread::sleep_for(chrono::milliseconds(1));
  }

  visible = true;
}

void Soul::mover(int direccion){
  switch (direccion) {
    case 1:{
      if (posicionY - velocidad > 0) {
        posicionY -= velocidad;
      }
      break;
    }
    case 2:{
      if (posicionY + velocidad < bounds.h - altura) {
        posicionY += velocidad;
      }
      break;
    }
    case 3:{
      if (posicionX - velocidad > 0) {
        posicionX -= velocidad;
      }
      break;
    }
    case 4:{
      if (posicionX + velocidad < bounds.w - anchura) {
        posicionX += velocidad;
      }
      break;
    }
  }
}

void Soul::terminarTrap(){
  salirTrap = true;
}

SDL_Rect Soul::getBounds(){
  return bounds;
}

void Soul::setBounds(SDL_Rect nBounds){
  bounds = nBounds;
}

void Soul::centrar(){
  posicionX = bounds.w/2;
  posicionY = bounds.h/2;
}

SDL_Surface* Soul::toSuperficie(){
  if (visible) {
    return sprite.toSuperficie();
  }else{
    return NULL;
  }
}

bool Soul::refrescar(){
  std::cout << "[SOUL] Refrescando..." << '\n';
  return true;
}
