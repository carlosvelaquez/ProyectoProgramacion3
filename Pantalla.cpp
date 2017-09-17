#include "Pantalla.h"

Pantalla::Pantalla(int nAltura, int nAnchura){
  altura = nAltura;
  anchura = nAnchura;

  superficie = SDL_SetVideoMode(anchura, altura, 32, SDL_SWSURFACE);
  if (superficie == NULL) {
    std::cout << "[PANTALLA] Error al inicializar pantalla." << '\n';
  }else{
    SDL_WM_SetCaption("Progratale Pre-Alpha v0.1", NULL);
    std::cout << "[PANTALLA] Pantalla inicializada exitosamente." << '\n';
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
  aplicarSuperficie(escenario->getFondo().toSuperficie(), -1, -1);

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

    }else{
      //std::cout << "[PANTALLA] El escenario cargado no tiene un espacio." << '\n';
    }

    if (escenario->getHUD() != NULL) {
      //TODO: Aplicar HUD

      vector<ElementoGUI*> elementos = escenario->getHUD()->getElementos();
      for (int i = 0; i < elementos.size(); i++) {
        ElementoGUI* elem = elementos[i];
        aplicarSuperficie(elem->toSuperficie(), elem->getPosicionX(), elem->getPosicionY());
      }
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

void Pantalla::aplicarSuperficie(SDL_Surface* sup, int x, int y){
  if (x == -1 && y == -1) {
    SDL_Rect offset;
    offset.x = 0;
    offset.y = 0;

    SDL_BlitSurface(sup, NULL, superficie, &offset);
  }else{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(sup, NULL, superficie, &offset);
    SDL_FreeSurface(sup);
  }

}

Pantalla::~Pantalla(){
  delete escenario;
  /*if (superficieActual != NULL) {
  SDL_FreeSurface(superficieActual);
}*/
SDL_FreeSurface(superficie);
std::cout << "[PANTALLA] Pantalla destruida." << '\n';
}
