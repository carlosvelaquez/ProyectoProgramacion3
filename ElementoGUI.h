#pragma once

class ElementoGUI{

protected:
  int anchura;
  int altura;
  int posicionX;
  int posicionY;

public:
  int getAnchura();
  int getAltura();
  int getPosicionX();
  int getPosicionY();

  void setAnchura(int);
  void setAltura(int);
  void setPosicionX(int);
  void setPosicionY(int);

  virtual SDL_Surface* toSuperficie() = 0;
};
