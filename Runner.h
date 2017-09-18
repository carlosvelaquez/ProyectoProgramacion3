#pragma once

#include "Ataque.h"
//#include "AtaqueJugador.h"
//#include "Batalla.h"
//#include "Boton.h"
//#include "BotonAccion.h"
//#include "ControladorInputs.h"
#include "ElementoGUI.h"
#include "BarraProgreso.h"
//#include "Enemigo.h"
#include "Escenario.h"
#include "Espacio.h"
#include "HUD.h"
#include "Imagen.h"
//#include "Label.h"
//#include "MedidorAtaque.h"
#include "Menu.h"
//#include "MostradorTexto.h"
#include "Pantalla.h"
#include "Prop.h"
#include "Proyectil.h"
#include "Sprite.h"
#include "Tablero.h"
#include "Texto.h"
#include "Audio.h"
#include "Sonido.h"
#include "Musica.h"
#include "DesplazadorTexto.h"
#include "TextManager.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_thread.h"

class Runner{
private:
  int init = 1;
  Pantalla* pantalla = NULL;
  bool vivo;

public:
  Runner();
  void playIntro();
  void iniciarRefresher();

  int run();

  ~Runner();
};
