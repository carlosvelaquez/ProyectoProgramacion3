#include "Menu.h"

Menu::Menu(){
  elementos.clear();
  visible = false;
  indice = 0;
  tipo = 1;
  wrap = 5;

  colorActivo = {255, 247, 78};
  colorInactivo = {255, 255, 255};
}

vector<Texto> Menu::getElementos(){
  return elementos;
}

bool Menu::isActivo(){
  return activo;
}

bool Menu::isVisible(){
  return visible;
}

int Menu::getIndice(){
  return indice;
}

int Menu::getTipo(){
  return tipo;
}

int Menu::getWrap(){
  return wrap;
}

void Menu::setElementos(vector<Texto> nElementos){
  elementos = nElementos;
}

void Menu::setActivo(bool nActivo){
  activo = nActivo;
}

void Menu::setVisible(bool nVisible){
  visible = nVisible;
}

void Menu::setIndice(int nIndice){
  indice = nIndice;
}

void Menu::setTipo(int nTipo){
  tipo = nTipo;
}

void Menu::setWrap(int nWrap){
  wrap = nWrap;
}

SDL_Surface* Menu::toSuperficie(){
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
        if (i%wrap == 0 && i != 0) {
          multVertical = 0;
          multHorizontal ++;
        }else{
          multVertical++;
        }

      }else if (tipo == 2){
        if (i%wrap == 0 && i != 0) {
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
}

bool Menu::refrescar(){
  std::cout << "[Menu] Refrescando..." << '\n';
  return true;
}

void Menu::indiceUp(){
  if (indice + 1 < elementos.size()) {
    indice++;
  }else{
    indice = 0;
  }
}

void Menu::indiceDown(){
  if (indice - 1 < 0) {
    indice = elementos.size() - 1;
  }else{
    indice--;
  }
}

int Menu::trap(){
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
                indiceDown();
                break;
              }
              case SDLK_DOWN:{
                indiceUp();
                break;
              }
              case SDLK_LEFT:{
                for (size_t i = 0; i <= wrap; i++) {
                  indiceDown();
                };
                break;
              }
              case SDLK_RIGHT:{
                for (size_t i = 0; i <= wrap; i++) {
                  indiceUp();
                };
                break;
              }
              case SDLK_x:{
                salir = true;
                break;
              }
              case SDLK_z:{
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
                indiceUp();
                break;
              }
              case SDLK_LEFT:{
                indiceDown();
                break;
              }
              case SDLK_UP:{
                for (size_t i = 0; i <= wrap; i++) {
                  indiceDown();
                };
                break;
              }
              case SDLK_DOWN:{
                for (size_t i = 0; i <= wrap; i++) {
                  indiceUp();
                };
                break;
              }
              case SDLK_x:{
                salir = true;
                break;
              }
              case SDLK_z:{
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
}

void Menu::addElemento(Texto nElemento){
  elementos.push_back(nElemento);
}

void Menu::clear(){
  elementos.clear();
}

SDL_Color Menu::getColorActivo(){
  return colorActivo;
}

SDL_Color Menu::getColorInactivo(){
  return colorInactivo;
}

void Menu::setColorActivo(SDL_Color nColor){
  colorActivo = nColor;
}

void Menu::setColorInactivo(SDL_Color nColor){
  colorInactivo = nColor;
}
