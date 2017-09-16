#include "Texto.h"

Texto::Texto(){
  texto = "Placeholder";
  size = 20;
  wrap = 10;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  refrescar();
  recargarFont();
}

Texto::Texto(string nTexto){
  texto = nTexto;
  size = 20;
  wrap = 10;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  refrescar();
  recargarFont();
}

Texto::Texto(string nTexto, int nSize){
  texto = nTexto;
  size = nSize;
  wrap = 10;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  refrescar();
  recargarFont();
}

Texto::Texto(string nTexto, int nSize, int nWrap){
  texto = nTexto;
  size = nSize;
  wrap = nWrap;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  refrescar();
  recargarFont();
}

Texto::Texto(string nTexto, int nSize, int nWrap, SDL_Color nColor){
  texto = nTexto;
  size = nSize;
  wrap = nWrap;
  color = nColor;
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  refrescar();
  recargarFont();
}

Texto::Texto(string nTexto, int nSize, int nWrap, SDL_Color nColor, string nRutaFont){
  texto = nTexto;
  size = nSize;
  wrap = nWrap;
  color = nColor;
  rutaFont = nRutaFont;
  refrescar();
  recargarFont();
}

string Texto::getTexto(){
  return texto;
}

int Texto::getSize(){
  return size;
}

int Texto::getLength(){
  return length;
}

int Texto::getWrap(){
  return wrap;
}

SDL_Color Texto::getColor(){
  return color;
}

TTF_Font* Texto::getFont(){
  return font;
}

SDL_Surface* Texto::toSuperficie(){
  recargarFont();
  refrescar();

  SDL_Surface* s = TTF_RenderText_Solid(font, texto.c_str(), color);
  TTF_CloseFont(font);
  //std::cout << "[TEXTO] Font cerrada." << '\n';
  return s;
}

void Texto::setTexto(string nTexto){
  texto = nTexto;
}

void Texto::setSize(int nSize){
  size = nSize;
  refrescar();
}

void Texto::setWrap(int nWrap){
  wrap = nWrap;
  refrescar();
}

void Texto::setColor(SDL_Color nColor){
  color = nColor;
  refrescar();
}

void Texto::cargarFont(string nRutaFont){
  rutaFont = nRutaFont;
  recargarFont();
  refrescar();
}

bool Texto::refrescar(){
  length = texto.length();
  altura = size;
  anchura = (size*.75)*length;
}

bool Texto::recargarFont(){
  font = TTF_OpenFont(rutaFont.c_str(), size);

  if (font) {
    //std::cout << "[TEXTO] Font cargada exitosamente de " << rutaFont << '\n';
    return true;
  }

  std::cout << "[TEXTO] Error al cargar font de " << rutaFont << '\n';
  return false;
}

Texto::~Texto(){
  refrescar();
  //TTF_CloseFont(font);
}
