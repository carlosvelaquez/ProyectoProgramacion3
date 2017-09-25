class Tablero
!!!164475.cpp!!!	Tablero()
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
!!!164603.cpp!!!	getModo() : int
  return modo;
!!!164731.cpp!!!	getProyectiles() : vector<Proyectil*>
  return proyectiles;
!!!164859.cpp!!!	getElementos() : vector<ElementoGUI*>
  return elementosGUI;
!!!164987.cpp!!!	isListo() : bool
  return listo;
!!!165243.cpp!!!	isVisible() : bool
  return visible;
!!!165371.cpp!!!	addElemento(inout nElemento : ElementoGUI) : void
  elementosGUI.push_back(nElemento);
!!!165499.cpp!!!	setProyectiles(inout nProyectiles : vector<Proyectil*>) : void
  proyectiles = nProyectiles;
!!!165755.cpp!!!	setVisible(in nVisible : bool) : void
  visible = nVisible;
!!!165883.cpp!!!	toSuperficie() : SDL_Surface
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
!!!166011.cpp!!!	refrescar() : bool
  cout << "[TABLERO] Refrescando..." << endl;
  return true;
!!!166139.cpp!!!	modoAtaque(inout ataque : Ataque) : void
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
!!!166267.cpp!!!	modoDisplay() : void
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
!!!166395.cpp!!!	activar(inout ataque : Ataque, in atk : int) : void
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
!!!166523.cpp!!!	cambiarTamano(in nAnchura : int, in nAltura : int) : void
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
!!!165115.cpp!!!	getSoul() : Soul
  return soul;
!!!165627.cpp!!!	setSoul(inout nSoul : Soul) : void
  soul = nSoul;
!!!166651.cpp!!!	~Tablero()
  if (proyectiles != NULL) {
    delete proyectiles;
  }
