#include "TextManager.h"

TextManager::TextManager(Texto* texto, int nMultiplicador, Sonido* sonido, long velocidad){
  desplazadores.clear();
  vector<string> strings;
  strings.clear();

  string s = texto->getTexto();
  int ind = 0;

  while (ind < texto->getTexto().length()) {
    int i;
    string str = "";

    for (i = 0; i < texto->getWrap(); i++) {
      if (s[i + ind] == '\n') {
        i++;
        break;
      }
      str += s[i + ind];
    }

    ind += i;
    std::cout << str << '\n';

    desplazadores.push_back(new DesplazadorTexto(str, sonido, velocidad));
  }

  setVisible(false);
  multiplicador = nMultiplicador;
}

int TextManager::getMultiplicador(){
  return multiplicador;
}

void TextManager::setMultiplicador(int nMultiplicador){
  multiplicador = nMultiplicador;
}

int TextManager::getPosicionX(){
  if (desplazadores.size() > 0) {
    return desplazadores[0]->getPosicionX();
  }else{
    return -1;
  }
}

int TextManager::getPosicionY(){
  if (desplazadores.size() > 0) {
    return desplazadores[0]->getPosicionY();
  }else{
    return -1;
  }
}

void TextManager::setPosicionX(int nPos){
  if (desplazadores.size() > 0) {
    desplazadores[0]->setPosicionX(nPos);
  }
}

void TextManager::setPosicionY(int nPos){
  if (desplazadores.size() > 0) {
    desplazadores[0]->setPosicionY(nPos);
  }
}

vector<DesplazadorTexto*> TextManager::getDesplazadores(){
  return desplazadores;
}

void TextManager::setDesplazadores(vector<DesplazadorTexto*> nDesplazadores){
  desplazadores = nDesplazadores;
}

void TextManager::addDesplazador(DesplazadorTexto* nDesplazador){
  desplazadores.push_back(nDesplazador);
}

void TextManager::setVisible(bool nVisible){
  for (int i = 0; i < desplazadores.size(); i++) {
    desplazadores[i]->setVisible(nVisible);
  }
}

void TextManager::iniciar(){
  setVisible(false);

  thread ejecucion (&TextManager::desplazar, this);
  ejecucion.detach();
}

void TextManager::desplazar(){
  for (int i = 0; i < desplazadores.size(); i++) {
    desplazadores[i]->setPosicionY((i*multiplicador) + desplazadores[0]->getPosicionY());
    desplazadores[i]->setPosicionX(desplazadores[0]->getPosicionX());
    desplazadores[i]->setVisible(true);
    desplazadores[i]->iniciar();

    while (desplazadores[i]->isActivo()) {
      this_thread::sleep_for(chrono::milliseconds(100));
    }
  }
}

SDL_Surface* TextManager::toSuperficie(){
  SDL_Surface* superficie = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 480, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);

  for (int i = 0; i < desplazadores.size(); i++) {
    if (desplazadores[i]->isVisible()){
      SDL_Rect offset2;
      offset2.x = desplazadores[i]->getPosicionX();
      offset2.y = desplazadores[i]->getPosicionY();

      SDL_BlitSurface(desplazadores[i]->toSuperficie(), NULL, superficie, &offset2);
    }
  }

  return superficie;
}

bool TextManager::refrescar(){
  return true;
}
