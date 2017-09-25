#ifndef _TEXTO_H
#define _TEXTO_H


#include "ElementoGUI.h"
#include <string>
using namespace std;
#include <vector>
using namespace std;

class Texto : public ElementoGUI {
  private:
    string texto;

    int size;

    int length;

    int wrap;

    SDL_Color color;

    TTF_Font * font;

    string rutaFont;

    vector<SDL_Surface*> superficies;


  public:
    Texto();

    Texto(string nTexto);

    Texto(string nTexto, int nSize);

    Texto(string nTexto, int nSize, int nWrap);

    Texto(string nTexto, int nSize, int nWrap, SDL_Color nColor);

    Texto(string nTexto, int nSize, int nWrap, SDL_Color nColor, string nRutaFont);

    string getTexto();

    int getSize();

    int getLength();

    int getWrap();

    SDL_Color getColor();

    TTF_Font * getFont();

    SDL_Surface * toSuperficie();

    void setTexto(string nTexto);

    void setSize(int nSize);

    void setWrap(int nWrap);

    void setColor(SDL_Color nColor);

    void cargarFont(string nRutaFont);

    bool refrescar();

    bool recargarFont();

    friend inline istream & operator >>(istream & input, Texto t) {
        string s;
        getline(input, s);
        t.setTexto(s);
        return input;
      };

    ~Texto();

};
#endif
