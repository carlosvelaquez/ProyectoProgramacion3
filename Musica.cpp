#include "Musica.h"

Musica::Musica(string nRuta){
  ruta = nRuta;
  cargar();
}

bool Musica::cargar(){
  musica = Mix_LoadMUS(ruta.c_str());

  if (musica == NULL) {
    std::cout << "[MUSICA] Error al cargar musica de " << ruta << '\n';
    cargado = false;
  }else{
    cargado = true;
  }

  return cargado;
}

bool Musica::reproducir(){
  if (Mix_PlayMusic(musica, -1) == -1) {
    std::cout << "[MUSICA] Error al reproducir musica cargada de " << ruta << '\n';
    return false;
  }

  return true;
}

bool Musica::pausar(){
  if (Mix_PlayingMusic() == 0) {
    std::cout << "[MUSICA] Orden de pausa recibida, pero no hay musica reproduciendose." << '\n';
  }else{
    if (Mix_PausedMusic() == 1) {
      std::cout << "[MUSICA] Orden de pausa recibida, pero la musica ya está pausada." << '\n';
    }else{
      Mix_PauseMusic();
      return true;
    }
  }

  return false;
}

bool Musica::resumir(){
  if (Mix_PausedMusic() == 1) {
    Mix_ResumeMusic();
    return true;
  }else{
    std::cout << "[MUSICA] Orden de resumir recibida, pero no hay musica pausada." << '\n';
  }

  return false;
}

void Musica::parar(){
  Mix_HaltMusic();
}

Musica::~Musica(){
  Mix_FreeMusic(musica);
}
