#ifndef _MENU_H
#define _MENU_H


#include "ElementoGUI.h"
#include <vector>
using namespace std;

class Texto;
class Sonido;

class Menu : public ElementoGUI {
  private:
    vector<Texto> elementos;

    bool activo;

    bool visible;

    int indice;

    int tipo;

    int wrap;

    SDL_Color colorActivo;

    SDL_Color colorInactivo;

    Sonido * sonidoMove;

    Sonido * sonidoSelect;


  public:
    Menu();

    vector<Texto> getElementos();

    bool isActivo();

    bool isVisible();

    int getIndice();

    int getTipo();

    int getWrap();

    void setElementos(vector<Texto> nElementos);

    void setActivo(bool nActivo);

    void setVisible(bool nVisible);

    void setIndice(int nIndice);

    void setTipo(int nTipo);

    void setWrap(int nWrap);

    SDL_Surface * toSuperficie();

    bool refrescar();

    void indiceUp();

    void indiceDown();

    int trap();

    void addElemento(Texto nElemento);

    void chop();

    void clear();

    SDL_Color getColorActivo();

    SDL_Color getColorInactivo();

    void setColorActivo(SDL_Color nColor);

    void setColorInactivo(SDL_Color nColor);

};
#endif
