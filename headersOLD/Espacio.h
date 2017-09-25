#ifndef _ESPACIO_H
#define _ESPACIO_H


#include <vector>
using namespace std;

class Prop;

class Espacio {
  private:
    vector<Prop> props;

    int altura;

    int anchura;


  public:
    Espacio(int nAltura, int nAnchura);

    Espacio(int nAltura, int nAnchura, vector<Prop> nProps);

    vector<Prop> getProps();

    int getAltura();

    int getAnchura();

    void setProps(vector<Prop> nProps);

    void setAltura(int nAltura);

    void setAnchura(int nAnchura);

    void addProp(Prop nProp);

};
#endif
