#pragma once
#include "ElementoGUI.h"
#include "Sonido.h"
#include "Texto.h"
#include <thread>
#include <chrono>

class DesplazadorTexto : public ElementoGUI{
private:
  Texto texto;
  Sonido* sonido;
  long velocidad;
  bool activo;
  bool visible;
  bool mute = false;

public:
  DesplazadorTexto(Texto, Sonido*, long);

  Texto getTexto();
  Sonido* getSonido();
  long getVelocidad();
  bool isActivo();
  bool isVisible();
  bool isMuted();

  void setTexto(Texto);
  void setSonido(Sonido*);
  void setVelocidad(long);
  void setVisible(bool);
  void setMute(bool);

  void iniciar();
  void desplazar();

  SDL_Surface* toSuperficie();
  bool refrescar();
};
