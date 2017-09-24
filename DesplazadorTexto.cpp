#include "DesplazadorTexto.h"

DesplazadorTexto::DesplazadorTexto(Texto nTexto, Sonido* nSonido, long nVelocidad){
  texto = nTexto;
  sonido = nSonido;
  velocidad = nVelocidad;
  posicionX = 0;
  posicionY = 0;
}

Texto DesplazadorTexto::getTexto(){
  return texto;
}

Sonido* DesplazadorTexto::getSonido(){
  return sonido;
}

long DesplazadorTexto::getVelocidad(){
  return velocidad;
}

bool DesplazadorTexto::isActivo(){
  return activo;
}

bool DesplazadorTexto::isMuted(){
  return mute;
}

void DesplazadorTexto::setTexto(Texto nTexto){
  texto = nTexto;
}

void DesplazadorTexto::setSonido(Sonido* nSonido){
  sonido = nSonido;
}

void DesplazadorTexto::setVelocidad(long nVelocidad){
  velocidad = nVelocidad;
}

void DesplazadorTexto::iniciar(){
  activo = true;
  thread desplazador (&DesplazadorTexto::desplazar, this);
  desplazador.detach();
}

void DesplazadorTexto::desplazar(){
  Texto tempTexto = texto;
  string textoActual;

  for (int i = 0; i < tempTexto.getTexto().length(); i++) {
    textoActual = "";

    for (int j = 0; j < i; j++) {
      textoActual += tempTexto.getTexto()[j];
    }

    texto.setTexto(textoActual);
    texto.refrescar();

    if (tempTexto.getTexto()[i] != ' ' && mute == false) {
      sonido->reproducir();
    }

    this_thread::sleep_for(chrono::milliseconds(velocidad));
  }

  texto = tempTexto;
  activo = false;
}

SDL_Surface* DesplazadorTexto::toSuperficie(){
  if (visible) {
    return texto.toSuperficie();
  }else{
    return NULL;
  }
}

bool DesplazadorTexto::refrescar(){
  texto.refrescar();
}

bool DesplazadorTexto::isVisible(){
  return visible;
}

void DesplazadorTexto::setVisible(bool nVisible){
  visible = nVisible;
}

void DesplazadorTexto::setMute(bool nMute){
  mute = nMute;
}
