
#include "Tablero.h"
#include "Proyectil.h"
#include "Soul.h"
#include "Ataque.h"

Tablero::Tablero(){
  modo = 1;
  proyectiles = NULL;
  elementosGUI.clear();
  listo = true;
  anchura = 600;
  altura = 120;
  posicionX = 20;
  posicionY = 260;
  visible = false;
  sonidoDano = Sonido(("./assets/sonidos/dano.wav"));
}

int Tablero::getModo() {
  return modo;
}

vector<Proyectil*> * Tablero::getProyectiles() {
  return proyectiles;
}

vector<ElementoGUI*> Tablero::getElementos() {
  return elementosGUI;
}

bool Tablero::isListo() {
  return listo;
}

Soul * Tablero::getSoul() {
  return soul;
}

bool Tablero::isVisible() {
  return visible;
}

void Tablero::addElemento(ElementoGUI * nElemento) {
  elementosGUI.push_back(nElemento);
}

void Tablero::setProyectiles(vector<Proyectil*> * nProyectiles) {
  proyectiles = nProyectiles;
}

void Tablero::setSoul(Soul * nSoul) {
  soul = nSoul;
}

void Tablero::setVisible(bool nVisible) {
  visible = nVisible;
}

SDL_Surface * Tablero::toSuperficie() {
  if (!visible) {
    return NULL;
  }

  SDL_Surface* superficie = SDL_CreateRGBSurface(SDL_HWSURFACE, anchura, altura, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
  SDL_FillRect(superficie, &superficie->clip_rect, SDL_MapRGB(superficie->format, 0xFF, 0xFF, 0xFF));

  SDL_Rect offset;
  offset.x = 2;
  offset.y = 2;
  offset.w = anchura-4;
  offset.h = altura-4;
  SDL_FillRect(superficie, &offset, SDL_MapRGB(superficie->format, 0x00, 0x00, 0x00));

  if (listo) {
    if (modo == 1) {
      int size = elementosGUI.size();
      for (int i = 0; i < elementosGUI.size(); i++) {
        SDL_Rect offset2;
        offset2.x = elementosGUI[i]->getPosicionX();
        offset2.y = elementosGUI[i]->getPosicionY();

        SDL_BlitSurface(elementosGUI[i]->toSuperficie(), NULL, superficie, &offset2);
      }
    }else if (modo == 2){
      SDL_Rect offset;
      offset.x = soul->getPosicionX();
      offset.y = soul->getPosicionY();
      SDL_BlitSurface(soul->toSuperficie(), NULL, superficie, &offset);

      if (proyectiles != NULL) {
        for (int i = 0; i < proyectiles->size(); i++) {
          SDL_Rect offset2;
          offset2.x = proyectiles->at(i)->getPosicionX();
          offset2.y = proyectiles->at(i)->getPosicionY();

          SDL_BlitSurface(proyectiles->at(i)->getSprite().toSuperficie(), NULL, superficie, &offset2);
        }
      }


    }
  }

  return superficie;
}

bool Tablero::refrescar() {
  cout << "[TABLERO] Refrescando..." << endl;
  return true;
}

void Tablero::modoAtaque(Ataque * ataque) {
  if (modo == 2) {
    std::cout << "[TABLERO] Orden de cambiar a modo ataque recibida, pero el tablero ya está en modo ataque." << '\n';
  }else{
    std::cout << "[TABLERO] Cambiando a modo ataque." << '\n';

    if (ataque != NULL) {
      //thread ejecucion2 (&Tablero::activar, this, ataque);
      //ejecucion2.detach();
      thread ejecucion (&Tablero::cambiarTamano, this, ataque->getAnchuraTablero(), ataque->getAlturaTablero());
      ejecucion.detach();
    }else{
      thread ejecucion (&Tablero::cambiarTamano, this, 150, 150);
      ejecucion.detach();
    }


    modo = 2;
    this_thread::sleep_for(chrono::milliseconds(30));
    modo = 2;
  }
}

void Tablero::modoDisplay() {
  if (modo == 1) {
    std::cout << "[TABLERO] Orden de cambiar a modo display recibida, pero el tablero ya está en modo display." << '\n';
  }else{
    modo = 1;
    this_thread::sleep_for(chrono::milliseconds(30));
    modo = 1;

    std::cout << "[TABLERO] Cambiando a modo display." << '\n';
    thread ejecucion (&Tablero::cambiarTamano, this, 600, 120);
    ejecucion.detach();
  }
}

void Tablero::activar(Ataque * ataque, int atk) {
  cout << "[TABLERO] Activando ataque..." << endl;
  proyectiles = ataque->proyectilesActivos;
  int cantidadProyectiles = ataque->proyectilesActivos->size();
  cout << "[TABLERO] Cantidad de proyectiles: " <<  cantidadProyectiles << endl;

  ataque->activar();

  while (ataque->activo) {
    for (int i = 0; i < proyectiles->size(); i++) {
      Proyectil* p = proyectiles->at(i);
      int posXP, posYP, posXS, posYS;

      posXP = p->getPosicionX();
      posYP = p->getPosicionY();
      posXS = soul->getPosicionX();
      posYS = soul->getPosicionX();

      //cout << posXP << " - " << posYP << " - " << posXS << " - " << posYS << " - " << endl;

      if ((posXS + 8) >= posXP && (posXS + 8) <= (posXP + p->getAnchura())) {
        if ((posYS + 8) >= posYP && (posYS + 8) <= (posYP + p->getAltura())) {
          soul->blink();
          //sonidoDano.reproducir();
          soul->setHP(soul->getHP() - atk);
          this_thread::sleep_for(chrono::milliseconds(250));
        }
      }
    }
    this_thread::sleep_for(chrono::milliseconds(100));
  }

  proyectiles = NULL;
  std::cout << "[TABLERO] Ataque terminado." << '\n';
  soul->terminarTrap();
  //modoDisplay();
}

void Tablero::cambiarTamano(int nAnchura, int nAltura) {
  if (!listo) {
    std::cout << "[TABLERO] El tablero tiene una orden de cambio de tamaño pendiente." << '\n';
  }else{
    bool termino = false;
    listo = false;
    int posX = (640-nAnchura)/2;

    while (!termino) {
      if (anchura != nAnchura || altura != nAltura || posicionX != posX) {
        if (anchura != nAnchura) {
          if (anchura < nAnchura) {
            anchura++;
          }else{
            anchura--;
          }
        }

        if (altura != nAltura) {
          if (altura < nAltura) {
            altura++;
            posicionY--;
          }else{
            altura--;
            posicionY++;
          }
        }

        if (posicionX != posX) {
          if (posicionX < posX ) {
            posicionX++;
          }else{
            posicionX --;
          }
        }

        this_thread::sleep_for(chrono::milliseconds(2));
      }else{
        termino = true;
      }
    }

    listo = true;
  }
}

Tablero::~Tablero(){
  if (proyectiles != NULL) {
    delete proyectiles;
  }
}

