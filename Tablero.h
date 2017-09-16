#pragma once
#include <vector>
#include <thread>
#include "ElementoGUI.h"
#include "Proyectil.h"
#include "Ataque.h"

class Tablero : public ElementoGUI{
private:
  int modo;
  vector<Proyectil>* proyectiles;
  vector<ElementoGUI*> elementosGUI;
  bool listo;

public:
  Tablero();

  int getModo();
  vector<Proyectil>* getProyectiles();
  vector<ElementoGUI*> getElementos();

  void addElemento(ElementoGUI*);
  void setProyectiles(vector<Proyectil>*);

  SDL_Surface* toSuperficie();
  bool refrescar();

  void modoAtaque(Ataque*);
  void modoDisplay();
  void activar(Ataque*);

  void cambiarTamano(int, int);

  ~Tablero();
};
