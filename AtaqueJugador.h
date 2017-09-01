#pragma once
#include "ElementoGUI.h"
#include "Sprite.h"
#include "Sonido.h"

class AtaqueJugador : public ElementoGUI{
private:
  Sonido sonido;
  Sprite sprite;
public:
  Sonido getSonido();
  Sprite getSprite();

  void setSonido(Sonido*);
  void setSprite(Sprite*);
};
