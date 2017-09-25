class Pantalla
!!!152827.cpp!!!	Pantalla(in nAltura : int, in nAnchura : int)
  altura = nAltura;
  anchura = nAnchura;

  superficie = SDL_SetVideoMode(anchura, altura, 32, SDL_SWSURFACE);
  if (superficie == NULL) {
    std::cout << "[PANTALLA] Error al inicializar pantalla." << '\n';
  }else{
    SDL_WM_SetCaption("Progratale Pre-Alpha v0.1", NULL);
    std::cout << "[PANTALLA] Pantalla inicializada exitosamente." << '\n';
  }

!!!152955.cpp!!!	getEscenario() : Escenario
  return escenario;
!!!153083.cpp!!!	getAltura() : int
  return altura;
!!!153211.cpp!!!	getAnchura() : int
  return anchura;
!!!153339.cpp!!!	setEscenario(inout nEscenario : Escenario) : void
  escenario = nEscenario;
!!!153467.cpp!!!	setAltura(in nAltura : int) : void
  altura = nAltura;
!!!153595.cpp!!!	setAnchura(in nAnchura : int) : void
  anchura = nAnchura;
!!!153723.cpp!!!	refrescar() : bool
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
!!!153851.cpp!!!	limpiar() : bool
  superficie = NULL;
  return true;
!!!153979.cpp!!!	aplicarSuperficie(inout sup : SDL_Surface, in x : int, in y : int) : void
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

!!!154107.cpp!!!	fade(in tipo : int, in duracion : long) : void
  if (duracion == 0) {
    duracion = 1;
  }

  if (tipo == 1) {
    SDL_Surface* superficie2 = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 480, 32, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF);
    int alpha = 0;

    while(alpha < 255){
      alpha ++;
      SDL_SetAlpha(superficie2, SDL_SRCALPHA, alpha);
      aplicarSuperficie(superficie2, 0, 0);
      this_thread::sleep_for(chrono::milliseconds(255/duracion));
    }
  }
!!!154235.cpp!!!	~Pantalla()
  delete escenario;
SDL_FreeSurface(superficie);
std::cout << "[PANTALLA] Pantalla destruida." << '\n';
