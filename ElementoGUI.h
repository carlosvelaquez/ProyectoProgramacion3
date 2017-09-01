#pragma once

class ElementoGUI{
private:
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
};
