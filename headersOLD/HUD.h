#ifndef _HUD_H
#define _HUD_H


#include <vector>
using namespace std;

class ElementoGUI;

class HUD {
  private:
    vector<ElementoGUI*> elementos;


  public:
    HUD();

    HUD(vector<ElementoGUI*> nElementos);

    void addElemento(ElementoGUI * nElemento);

    vector<ElementoGUI*> getElementos();

    void setElementos(vector<ElementoGUI*> nElementos);

    void removeElemento(int indice);

    ~HUD();

};
#endif
