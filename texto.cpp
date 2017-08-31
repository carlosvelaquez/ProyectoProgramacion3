#include "texto.h"

Texto::Texto(){
  texto = "Placeholder";
  size = 20;
  wrap = 10;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  refrescar();
}

Texto::Texto(string nTexto){
  texto = nTexto;
  size = 20;
  wrap = 10;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  refrescar();
}

Texto::Texto(string nTexto, int nSize){
  texto = nTexto;
  size = nSize;
  wrap = 10;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  refrescar();
}

Texto::Texto(string nTexto, int nSize, int nWrap){
  texto = nTexto;
  size = nSize;
  wrap = nWrap;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  refrescar();
}

Texto::Texto(string nTexto, int nSize, int nWrap, SDL_Color nColor){
  texto = nTexto;
  size = nSize;
  wrap = nWrap;
  color = nColor;
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  refrescar();
}

Texto::Texto(string nTexto, int nSize, int nWrap, SDL_Color nColor, string nRutaFont){
  texto = nTexto;
  size = nSize;
  wrap = nWrap;
  color = nColor;
  rutaFont = nRutaFont;
  refrescar();
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
  refrescar();
  return TTF_RenderText_Solid(font, texto.c_str(), color);
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
  refrescar();
}

void Texto::refrescar(){
  font = TTF_OpenFont(rutaFont.c_str(), size);
  length = texto.length();
}

int Texto::getDimX(){
  refrescar();
  return (size*.75)*length;
}

int Texto::getDimY(){
  return size;
}

Texto::~Texto(){
  refrescar();
  TTF_CloseFont(font);
}
