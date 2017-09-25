
#include "Espacio.h"
#include "Prop.h"

Espacio::Espacio(int nAltura, int nAnchura){
  altura = nAltura;
  anchura = nAnchura;
}

Espacio::Espacio(int nAltura, int nAnchura, vector<Prop> nProps){
  altura = nAltura;
  anchura = nAnchura;
  props = nProps;
}

vector<Prop> Espacio::getProps() {
  return props;
}

int Espacio::getAltura() {
  return altura;
}

int Espacio::getAnchura() {
  return anchura;
}

void Espacio::setProps(vector<Prop> nProps) {
  props = nProps;
}

void Espacio::setAltura(int nAltura) {
  altura = nAltura;
}

void Espacio::setAnchura(int nAnchura) {
  anchura = nAnchura;
}

void Espacio::addProp(Prop nProp) {
  props.push_back(nProp);
}

