
#include "BarraProgreso.h"

BarraProgreso::BarraProgreso(){
  SDL_Surface* superficie = SDL_CreateRGBSurface(SDL_HWSURFACE, anchura, altura, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
  colorFondo = SDL_MapRGB(superficie->format, 0x40, 0x40, 0x40);
  colorProgreso = SDL_MapRGB(superficie->format, 0x16, 0xFE, 0x07);
  SDL_FreeSurface(superficie);

  porcentaje = 100;
  porcentajeMax = 100;
  visible  = false;
}

BarraProgreso::BarraProgreso(float nPorcentaje, float nPorcentajeMax){
  SDL_Surface* superficie = SDL_CreateRGBSurface(SDL_HWSURFACE, anchura, altura, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
  colorFondo = SDL_MapRGB(superficie->format, 0x40, 0x40, 0x40);
  colorProgreso = SDL_MapRGB(superficie->format, 0x16, 0xFE, 0x07);
  SDL_FreeSurface(superficie);

  porcentaje = nPorcentaje;
  porcentajeMax = nPorcentajeMax;
  visible  = false;
}

BarraProgreso::BarraProgreso(float nPorcentaje, float nPorcentajeMax, Uint32 nFondo, Uint32 nProgreso){
  colorFondo = nFondo;
  colorProgreso = nProgreso;

  porcentaje = nPorcentaje;
  porcentajeMax = nPorcentajeMax;
  visible  = false;
}

Uint32 BarraProgreso::getColorFondo() {
  return colorFondo;
}

Uint32 BarraProgreso::getColorProgreso() {
  return colorProgreso;
}

float BarraProgreso::getPorcentaje() {
  return porcentaje;
}

float BarraProgreso::getPorcentajeMax() {
  return porcentajeMax;
}

bool BarraProgreso::isVisible() {
  return visible;
}

void BarraProgreso::setColorFondo(Uint32 nFondo) {
  colorFondo = nFondo;
}

void BarraProgreso::setColorProgreso(Uint32 nProgreso) {
  colorProgreso = nProgreso;
}

void BarraProgreso::setPorcentaje(float nPorcentaje) {
  porcentaje = nPorcentaje;
}

void BarraProgreso::setPorcentajeMax(float nPorcentajeMax) {
  porcentajeMax = nPorcentajeMax;
}

void BarraProgreso::setVisible(bool nVisible) {
  visible = nVisible;
}

SDL_Surface * BarraProgreso::toSuperficie() {
  if (visible) {
    SDL_Surface* superficie = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 480, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);

    SDL_Rect offset1;
    offset1.x = 0;
    offset1.y = 0;
    offset1.h = altura;
    offset1.w = anchura;
    SDL_FillRect(superficie, &offset1, colorFondo);

    SDL_Rect offset;
    offset.x = 0;
    offset.y = 0;
    offset.h = altura;
    offset.w = (anchura)*(porcentaje/porcentajeMax);
    SDL_FillRect(superficie, &offset, colorProgreso);

    return superficie;
  }else{
    return NULL;
  }
}

bool BarraProgreso::refrescar() {
  std::cout << "[BarraProgreso] Refrescando..." << '\n';
}

