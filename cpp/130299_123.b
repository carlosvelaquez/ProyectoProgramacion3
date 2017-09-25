class Menu
!!!148347.cpp!!!	Menu()
  elementos.clear();
  visible = false;
  indice = 0;
  tipo = 1;
  wrap = 5;

  colorActivo = {255, 247, 78};
  colorInactivo = {255, 255, 255};

  sonidoMove = new Sonido("./assets/sonidos/menuMove.wav");
  sonidoSelect = new Sonido("./assets/sonidos/menuSelect.wav");
!!!148475.cpp!!!	getElementos() : vector<Texto>
  return elementos;
!!!148603.cpp!!!	isActivo() : bool
  return activo;
!!!148731.cpp!!!	isVisible() : bool
  return visible;
!!!148859.cpp!!!	getIndice() : int
  return indice;
!!!148987.cpp!!!	getTipo() : int
  return tipo;
!!!149115.cpp!!!	getWrap() : int
  return wrap;
!!!149243.cpp!!!	setElementos(in nElementos : vector<Texto>) : void
  elementos = nElementos;
!!!149371.cpp!!!	setActivo(in nActivo : bool) : void
  activo = nActivo;
!!!149499.cpp!!!	setVisible(in nVisible : bool) : void
  visible = nVisible;
!!!149627.cpp!!!	setIndice(in nIndice : int) : void
  indice = nIndice;
!!!149755.cpp!!!	setTipo(in nTipo : int) : void
  tipo = nTipo;
!!!149883.cpp!!!	setWrap(in nWrap : int) : void
  wrap = nWrap;
!!!150011.cpp!!!	toSuperficie() : SDL_Surface
  if (visible && elementos.size() > 0) {
    SDL_Surface* superficie = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 480, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
    SDL_Rect offset;

    int lengthMayor = 0;

    for (int i = 0; i < elementos.size(); i++) {
      if (elementos[i].getLength() > lengthMayor) {
        lengthMayor = elementos[i].getLength();
      }

      elementos[i].setColor(colorInactivo);
    }

    int textoHeight = elementos[0].getSize();

    int multVertical = 0;
    int multHorizontal = 0;

    elementos[indice].setColor(colorActivo);

    for (int i = 0; i < elementos.size(); i++) {
      offset.x = multHorizontal*lengthMayor*textoHeight;
      offset.y = multVertical*textoHeight*1.5;

      SDL_BlitSurface(elementos[i].toSuperficie(), NULL, superficie, &offset);

      if (tipo == 1) {
        if ((i+1)%wrap == 0 && i != 0) {
          multVertical = 0;
          multHorizontal ++;
        }else{
          multVertical++;
        }

      }else if (tipo == 2){
        if ((i+1)%wrap == 0 && i != 0) {
          multVertical++;
          multHorizontal = 0;
        }else{
          multHorizontal++;
        }
      }
    }

    return superficie;

  }else{
    return NULL;
  }
!!!150139.cpp!!!	refrescar() : bool
  std::cout << "[Menu] Refrescando..." << '\n';
  return true;
!!!150267.cpp!!!	indiceUp() : void
  if (indice + 1 < elementos.size()) {
    indice++;
  }else{
    indice = 0;
  }
!!!150395.cpp!!!	indiceDown() : void
  if (indice - 1 < 0) {
    indice = elementos.size() - 1;
  }else{
    indice--;
  }
!!!150523.cpp!!!	trap() : int
  if (elementos.size() > 0) {
    SDL_Event ev;
    bool salir = false;
    bool back = false;

    while (!salir) {
      if (tipo == 1) {
        while (SDL_PollEvent(&ev)) {
          if (ev.type = SDL_KEYDOWN) {
            switch (ev.key.keysym.sym) {
              case SDLK_UP:{
                sonidoMove->reproducir();
                indiceDown();
                break;
              }
              case SDLK_DOWN:{
                sonidoMove->reproducir();
                indiceUp();
                break;
              }
              case SDLK_LEFT:{
                sonidoMove->reproducir();
                for (size_t i = 0; i < wrap; i++) {
                  indiceDown();
                };
                break;
              }
              case SDLK_RIGHT:{
                sonidoMove->reproducir();
                for (size_t i = 0; i < wrap; i++) {
                  indiceUp();
                };
                break;
              }
              case SDLK_x:{
                sonidoSelect->reproducir();
                salir = true;
                break;
              }
              case SDLK_z:{
                sonidoSelect->reproducir();
                salir = true;
                back = true;
                break;
              }
            }
          }

          if (!salir) {
            SDL_WaitEvent(&ev);
          }
        }
      }else if (tipo == 2){
        while (SDL_PollEvent(&ev)) {
          if (ev.type = SDL_KEYDOWN) {
            switch (ev.key.keysym.sym) {
              case SDLK_RIGHT:{
                sonidoMove->reproducir();
                indiceUp();
                break;
              }
              case SDLK_LEFT:{
                sonidoMove->reproducir();
                indiceDown();
                break;
              }
              case SDLK_UP:{
                sonidoMove->reproducir();
                for (size_t i = 0; i < wrap; i++) {
                  indiceDown();
                };
                break;
              }
              case SDLK_DOWN:{
                sonidoMove->reproducir();
                for (size_t i = 0; i < wrap; i++) {
                  indiceUp();
                };
                break;
              }
              case SDLK_x:{
                sonidoSelect->reproducir();
                salir = true;
                break;
              }
              case SDLK_z:{
                sonidoSelect->reproducir();
                return -1;
              }
            }
          }

          if (!salir) {
            SDL_WaitEvent(&ev);
          }
        }
      }
    }

    if (back) {
      return -1;
    }

    return indice;
  }else{
    std::cout << "[MENU] No se puede usar trap en un menú vacío." << '\n';
    return -2;
  }
!!!150651.cpp!!!	addElemento(in nElemento : Texto) : void
  elementos.push_back(nElemento);
!!!150779.cpp!!!	chop() : void
  elementos.pop_back();
!!!150907.cpp!!!	clear() : void
  elementos.clear();
!!!151035.cpp!!!	getColorActivo() : SDL_Color
  return colorActivo;
!!!151163.cpp!!!	getColorInactivo() : SDL_Color
  return colorInactivo;
!!!151291.cpp!!!	setColorActivo(in nColor : SDL_Color) : void
  colorActivo = nColor;
!!!151419.cpp!!!	setColorInactivo(in nColor : SDL_Color) : void
  colorInactivo = nColor;
