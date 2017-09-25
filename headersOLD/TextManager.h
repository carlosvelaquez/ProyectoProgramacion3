#ifndef _TEXTMANAGER_H
#define _TEXTMANAGER_H


#include "ElementoGUI.h"
#include <vector>
using namespace std;

class DesplazadorTexto;
class Texto;
class Sonido;

class TextManager : public ElementoGUI {
  private:
    vector<DesplazadorTexto*> desplazadores;

    int multiplicador;

    bool activo;


  public:
    TextManager(Texto * texto, int nMultiplicador, Sonido * sonido, long velocidad);

    void reconstruir(Texto * texto, int nMultiplicador, Sonido * sonido, long velocidad);

    int getMultiplicador();

    void setMultiplicador(int nMultiplicador);

    bool isActivo();

    int getPosicionX();

    int getPosicionY();

    void setPosicionX(int nPos);

    void setPosicionY(int nPos);

    void setVelocidad(long nVelocidad);

    vector<DesplazadorTexto*> getDesplazadores();

    void setDesplazadores(vector<DesplazadorTexto*> nDesplazadores);

    void addDesplazador(DesplazadorTexto * nDesplazador);

    void setVisible(bool nVisible);

    void setMute(bool nMute);

    void iniciar();

    void desplazar();

    void trap();

    SDL_Surface * toSuperficie();

    bool refrescar();

};
#endif
