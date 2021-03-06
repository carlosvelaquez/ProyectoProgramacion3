#pragma once
#include <vector>
#include <thread>
#include "ElementoGUI.h"
#include "Proyectil.h"
#include "Ataque.h"
#include "Soul.h"
#include "Sonido.h"

class Tablero : public ElementoGUI {
  private:
    int modo;
    vector<Proyectil*>* proyectiles;
    vector<ElementoGUI*> elementosGUI;

    Soul* soul;
    bool listo;
    bool visible;
    Sonido sonidoDano;

  public:
    Tablero();
    int getModo();

    vector<Proyectil*>* getProyectiles();
    vector<ElementoGUI*> getElementos();

    bool isListo();
    Soul* getSoul();
    bool isVisible();

    void addElemento(ElementoGUI* nElemento);
    void setProyectiles(vector<Proyectil*>* nProyectiles);
    void setSoul(Soul* nSoul);
    void setVisible(bool nVisible);

    SDL_Surface* toSuperficie();
    bool refrescar();

    void modoAtaque(Ataque* ataque);
    void modoDisplay();
    void activar(Ataque* ataque, int atk);
    void cambiarTamano(int nAnchura, int nAltura);

    ~Tablero();
};
