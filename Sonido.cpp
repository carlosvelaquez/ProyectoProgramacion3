
#include "Sonido.h"

Sonido::Sonido(){
  ruta = "./assets/sonidos/ui.wav";
  cargar();
}

Sonido::Sonido(string nRuta){
  ruta = nRuta;
  cargar();
}

bool Sonido::reproducir() {
  if (Mix_PlayChannel(-1, sonido, 0) == -1) {
    //std::cout << "[SONIDO] Error al reproducir sonido cargado de " << ruta << '\n';
    return false;
  }

  return true;
}

bool Sonido::cargar() {
  sonido = Mix_LoadWAV(ruta.c_str());

  if (sonido == NULL) {
    std::cout << "[SONIDO] Error al cargar sonido de " << ruta << '\n';
    cargado = false;
    return false;
  }else{
    std::cout << "[SONIDO] Sonido cargado exitosamente de " << ruta << '\n';
  }

  cargado = true;
  return true;
}

bool Sonido::parar() {
  if (Mix_HaltChannel(-1) == 0) {
    return true;
  }

  return false;
}

bool Sonido::verificar() {
  Mix_Chunk* s = NULL;
  s = Mix_LoadWAV(ruta.c_str());

  if (s != NULL) {
    Mix_FreeChunk(s);
    return true;
  }else{
    return false;
  }
}

string Sonido::identificar() {
  return string("Sonido cargado de " + ruta);
}

void Sonido::liberar() {
  if (sonido) {
    Mix_FreeChunk(sonido);
  }else{
    cout << "[SONIDO] Se trató de liberar un sonido que ya había sido liberado.";
  }
}

Sonido::~Sonido(){
  Mix_FreeChunk(sonido);
}
