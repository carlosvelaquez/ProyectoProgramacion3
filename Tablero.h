#pragma once
#include <vector>
#include <thread>
#include "ElementoGUI.h"
#include "Proyectil.h"
#include "Ataque.h"
#include "Soul.h"

class Tablero : public ElementoGUI{
private:
  int modo;
  vector<Proyectil>* proyectiles;
  vector<ElementoGUI*> elementosGUI;
  Soul* soul;
  bool listo;
  bool visible;

public:
  Tablero();

  int getModo();
  vector<Proyectil>* getProyectiles();
  vector<ElementoGUI*> getElementos();
  bool isListo();
  Soul* getSoul();
  bool isVisible();

  void addElemento(ElementoGUI*);
  void setProyectiles(vector<Proyectil>*);
  void setSoul(Soul*);
  void setVisible(bool);

  SDL_Surface* toSuperficie();
  bool refrescar();

  void modoAtaque(Ataque*);
  void modoDisplay();
  void activar(Ataque*);

  void cambiarTamano(int, int);

  ~Tablero();
};
