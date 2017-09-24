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
  bool activo;

public:
  TextManager(Texto*, int, Sonido*, long);
  void reconstruir(Texto*, int, Sonido*, long);

  int getMultiplicador();
  void setMultiplicador(int);
  bool isActivo();

  int getPosicionX();
  int getPosicionY();

  void setPosicionX(int);
  void setPosicionY(int);
  void setVelocidad(long);

  vector<DesplazadorTexto*> getDesplazadores();
  void setDesplazadores(vector<DesplazadorTexto*>);
  void addDesplazador(DesplazadorTexto*);
  void setVisible(bool);
  void setMute(bool);

  void iniciar();
  void desplazar();
  void trap();

  SDL_Surface* toSuperficie();
  bool refrescar();
};
