#include "Sonido.h"

Sonido::Sonido(string nRuta){
  ruta = nRuta;
  cargar();
}

bool Sonido::reproducir(){
  if (Mix_PlayChannel(-1, sonido, 0) == -1) {
    std::cout << "[SONIDO] Error al reproducir sonido cargado de " << ruta << '\n';
    return false;
  }

  return true;
}

bool Sonido::cargar(){
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

Sonido::~Sonido(){
  Mix_FreeChunk(sonido);
}
