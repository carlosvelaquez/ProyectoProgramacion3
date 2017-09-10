#include "Pantalla.h"

Pantalla::Pantalla(int nAltura, int nAnchura){
  altura = nAltura;
  anchura = nAnchura;

  if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
    std::cout << "[PANTALLA] Error al inicializar SDL." << '\n';
  }else{
    superficie = SDL_SetVideoMode(anchura, altura, 32, SDL_SWSURFACE);
    if (superficie == NULL) {
      std::cout << "[PANTALLA] Error al inicializar pantalla." << '\n';
    }else{
      SDL_WM_SetCaption("Progratale Pre-Alpha v0.1", NULL);
      std::cout << "[PANTALLA] Pantalla inicializada exitosamente." << '\n';
    }
  }

}

Escenario* Pantalla::getEscenario(){
  return escenario;
}

int Pantalla::getAltura(){
  return altura;
}

int Pantalla::getAnchura(){
  return anchura;
}

void Pantalla::setEscenario(Escenario* nEscenario){
  escenario = nEscenario;
}

void Pantalla::setAltura(int nAltura){
  altura = nAltura;
}

void Pantalla::setAnchura(int nAnchura){
  anchura = nAnchura;
}

bool Pantalla::refrescar(){
  aplicarSuperficie(escenario->getFondo().toSuperficie(), 0, 0);

  if (escenario != NULL){
    if (escenario->getEspacio() != NULL) {
      vector<Prop> propsCargar = escenario->getEspacio()->getProps();

      if (propsCargar.size() < 1) {
        std::cout << "[PANTALLA] El espacio del escenario no contiene props." << '\n';
      }else{
        for (int i = 0; i < propsCargar.size(); i++) {
          Prop propCargar = propsCargar.at(i);
          aplicarSuperficie(propCargar.getSprite().toSuperficie(), propCargar.getPosicionX(), propCargar.getPosicionY());
        }
      }

      //TODO: Aplicar HUD

    }else{
      std::cout << "[PANTALLA] El escenario cargado no tiene un espacio." << '\n';
    }
  }else{
    std::cout << "[PANTALLA] No hay escenario que cargar." << '\n';
  }

  if (SDL_Flip(superficie) == -1) {
    std::cout << "[PANTALLA] Error al actualizar la superficie." << '\n';
    return false;
  }

  return true;
}

bool Pantalla::limpiar(){
  superficie = NULL;
  return true;
}

void Pantalla::aplicarSuperficie(SDL_Surface* super, int x, int y){
  //Crear un rectangulo para contener los offsets
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  SDL_Rect origin;
  origin.x = 0;
  origin.y = 0;

  //"Blittear" la Superficies
  SDL_BlitSurface(super, NULL, superficie, &offset);
}

Pantalla::~Pantalla(){
  delete escenario;
  SDL_FreeSurface(superficie);
  std::cout << "[PANTALLA] Pantalla destruida." << '\n';
}
