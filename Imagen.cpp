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
    altura = imagenCargada->h;
    anchura = imagenCargada->w;
    superficie = SDL_DisplayFormat(imagenCargada);

    SDL_FreeSurface(imagenCargada);
    cargada = true;

  }else{
    std::cout << "[IMAGEN] Imagen en " << ruta << "no pudo ser cargada." << '\n';
    cargada = false;

    altura = 0;
    anchura = 0;
    return false;
  }

  return true;
}

int Imagen::getAnchura(){
  return anchura;
}

int Imagen::getAltura(){
  return altura;
}

SDL_Surface* Imagen::toSuperficie(){
  return superficie;
}

Imagen::~Imagen(){
  if (superficie != NULL) {
    //SDL_FreeSurface(superficie);
    //std::cout << "[IMAGEN] Imagen cargada de " << ruta << " destruida." << '\n';
  }
}
