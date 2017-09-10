#include "Runner.h"

Runner::Runner(){
  pantalla = new Pantalla(480, 640);
}

int Runner::run(){
  bool continuar = true;

  /*if (init != 0) {
    return 1;
  }*/

  if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
    std::cout << "[RUNNER] Error al inicializar sonido." << '\n';
    return 1;
  }

  SDL_Event evento;

  while (continuar) {
    while (SDL_PollEvent(&evento)) {
      if (evento.type = SDL_KEYDOWN) {
        if (evento.key.keysym.sym == SDLK_DOWN) {
          Imagen* fond = new Imagen("./assets/fondo.png");
          Escenario e;
          e.setFondo(*fond);
          pantalla->setEscenario(&e);
          pantalla->refrescar();
        }else if (evento.key.keysym.sym == SDLK_UP){
          continuar = false;
        }
      }

      if (evento.type == SDL_QUIT) {
        continuar = false;
      }
    }

  }


  return 0;
}
