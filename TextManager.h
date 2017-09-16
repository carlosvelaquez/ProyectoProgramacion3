#pragma once
#include "Texto.h"
#include "DesplazadorTexto.h"
#include <vector>
#include <thread>

using namespace std;

class TextManager : public ElementoGUI{
private:
  vector<DesplazadorTexto*> desplazadores;
  int multiplicador;

public:
  TextManager(Texto*, int, Sonido*, long);

  int getMultiplicador();
  void setMultiplicador(int);

  int getPosicionX();
  int getPosicionY();

  void setPosicionX(int);
  void setPosicionY(int);

  vector<DesplazadorTexto*> getDesplazadores();
  void setDesplazadores(vector<DesplazadorTexto*>);
  void addDesplazador(DesplazadorTexto*);
  void setVisible(bool);

  void iniciar();
  void desplazar();

  SDL_Surface* toSuperficie();
  bool refrescar();
};
