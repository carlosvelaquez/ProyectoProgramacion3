#include "Imagen.h"

Imagen::Imagen(){
  ruta = "./assets/soul.png";
  cargada = recargar();
}

Imagen::Imagen(string nRuta){
  ruta = nRuta;
  cargada = recargar();
}

bool Imagen::recargar(){
  SDL_Surface* imagenCargada = NULL;
  imagenCargada = IMG_Load(ruta.c_str());

  if (imagenCargada != NULL) {
    superficie = SDL_DisplayFormat(imagenCargada);
    SDL_FreeSurface(imagenCargada);
    cargada = true;
  }else{
    std::cout << "[IMAGEN] Imagen en " << ruta << "no pudo ser cargada." << '\n';
    cargada = false;
    return false;
  }

  return true;
}

SDL_Surface* Imagen::toSuperficie(){
  return superficie;
}

Imagen::~Imagen(){
  if (superficie != NULL) {
    //SDL_FreeSurface(superficie);
    std::cout << "[IMAGEN] Imagen cargada de " << ruta << " destruida." << '\n';
  }
}
