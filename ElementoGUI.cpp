
#include "ElementoGUI.h"

int ElementoGUI::getAnchura() {
  return anchura;
}

int ElementoGUI::getAltura() {
  return altura;
}

int ElementoGUI::getPosicionX() {
  return posicionX;
}

int ElementoGUI::getPosicionY() {
  return posicionY;
}

void ElementoGUI::setAnchura(int nAnchura) {
  anchura = nAnchura;
}

void ElementoGUI::setAltura(int nAltura) {
  altura = nAltura;
}

void ElementoGUI::setPosicionX(int posX) {
  posicionX = posX;
}

void ElementoGUI::setPosicionY(int posY) {
  posicionY = posY;
}

void ElementoGUI::centrar() {
  posicionX = 320 - (anchura/2);
  posicionY = 240 - (altura/2);
}

void ElementoGUI::setVisible(bool nVisible) {
  visible = nVisible;
}

bool ElementoGUI::isVisible() {
  return visible;
}

