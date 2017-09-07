#include "Imagen.h"

Imagen::Imagen(string nRuta){
  ruta = nRuta;
  cargada = recargar();
}

bool Imagen::recargar(){
  SDL_Surface* imagenCargada = NULL;
  imagenCargada = IMG_Load(ruta.c_str());

  if (imagenCargada != NULL) {
    superfice = SDL_DisplayFormat(imagenCargada);
    SDL_FreeSurface(imagenCargada);
    cargada = true;
  }else{
    std::cout << "[IMAGEN] Imagen en " << ruta << "no pudo ser cargada." << '\n';
    cargada = false;
    return false;
  }

  return true;
}

Imagen::~Imagen(){
  delete superficie;
}
