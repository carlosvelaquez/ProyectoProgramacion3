#include "Escenario.h"

Escenario::Escenario(){
  hud = NULL;
  espacio = NULL;
}

Imagen Escenario::getFondo(){
  return fondo;
}

HUD* Escenario::getHUD(){
  return hud;
}

int Escenario::getTipo(){
  return tipo;
}

Espacio* Escenario::getEspacio(){
  return espacio;
}

void Escenario::setFondo(Imagen nFondo){
  fondo = nFondo;
}

void Escenario::setHUD(HUD* nHud){
  hud = nHud;
}

void Escenario::setEspacio(Espacio* nEspacio){
  espacio = nEspacio;
}

Escenario::~Escenario(){
  delete hud;
  delete espacio;
}
