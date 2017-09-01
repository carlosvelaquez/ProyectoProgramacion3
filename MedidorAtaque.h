#pragma once
#include "ElementoGUI.h"
#include "Imagen.h"
#include "Sprite.h"

class MedidorAtaque : public ElementoGUI{
private:
  Imagen fondo;
  Sprite spriteAguja;
public:
  Imagen getFondo();
  Sprite getSpriteAguja();

  void setFondo(Imagen);
  void setSpriteAguja(Sprite);
};
