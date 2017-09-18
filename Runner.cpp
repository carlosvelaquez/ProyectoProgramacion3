#include "Runner.h"

Runner::Runner(){
  pantalla = new Pantalla(480, 640);
  vivo = true;
}

int Runner::run(){
  bool continuar = true;

  /*if (init != 0) {
    return 1;
  }*/

  if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
    std::cout << "[RUNNER] Error al inicializar SDL." << '\n';
  }

  if (TTF_Init() == -1) {
    std::cout << "[RUNNER] Error al inicializar TTF." << '\n';
  }

  if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
    std::cout << "[RUNNER] Error al inicializar audio." << '\n';
    return 1;
  }

  SDL_Event evento;

  std::cout << "[RUNNER] Cargando assets..." << '\n';
  Imagen* fond = new Imagen("./assets/fondo.png");
  Escenario e;

  Texto text("Hola amigo Josue, tus graficas ya deberian de estar hechas.");
  text.setWrap(43);
  text.setPosicionX(0);
  text.setPosicionY(0);

  Sonido sond("./assets/sonidos/dialogTest.wav");

  e.setFondo(*fond);
  e.setHUD(new HUD());

  TextManager* tm = new TextManager(&text, 25, &sond, 100);
  tm->setPosicionX(12);
  tm->setPosicionY(10);
  //e.getHUD()->addElemento(dt);

  Musica musica("./assets/musica/boss3.wav");
  Sonido intro("./assets/sonidos/intro.wav");
  std::cout << "[RUNNER] Assets cargados." << '\n';

  playIntro();
  pantalla->setEscenario(&e);

  std::cout << "[RUNNER] Creando tablero." << '\n';
  Tablero* t = new Tablero();
  t->addElemento(tm);
  e.getHUD()->addElemento(t);

  BarraProgreso* bp = new BarraProgreso();
  bp->setPosicionX(50);
  bp->setPosicionY(50);
  bp->setAltura(10);
  bp->setAnchura(50);

  Menu* mn = new Menu();
  mn->addElemento(Texto("Reproducir Sonido"));
  mn->addElemento(Texto("- - - - - - - - - -"));
  mn->addElemento(Texto("Reproducir Musica"));
  mn->addElemento(Texto("Pausar Musica"));
  mn->addElemento(Texto("Resumir Musica"));
  mn->addElemento(Texto("Parar Musica"));
  mn->addElemento(Texto("- - - - - - - - - -"));
  mn->addElemento(Texto("Probar TextManager"));
  mn->addElemento(Texto("Tablero Modo Display"));
  mn->addElemento(Texto("Tablero Modo Ataque"));
  mn->addElemento(Texto("- - - - - - - - - -"));
  mn->addElemento(Texto("Salir"));

  mn->setWrap(11);
  //mn->setTipo(2);
  mn->setPosicionX(0);
  mn->setPosicionY(0);

  e.getHUD()->addElemento(mn);
  e.getHUD()->addElemento(bp);

  while (continuar) {
    while (SDL_PollEvent(&evento)) {
      if (evento.type = SDL_KEYDOWN) {
        if (evento.key.keysym.sym == SDLK_UP || evento.key.keysym.sym == SDLK_DOWN){
          std::cout << "[RUNNER] Entrando a menu..." << '\n';
          mn->setVisible(true);

          switch (mn->trap()) {
            case 0:{
              std::cout << "[RUNNER] Reproduciendo sonido intro." << '\n';
              intro.reproducir();
              break;
            }
            case 2:{
              std::cout << "[RUNNER] Reproduciendo musica." << '\n';
              musica.reproducir();
              break;
            }
            case 3:{
              std::cout << "[RUNNER] Reproduciendo musica." << '\n';
              musica.pausar();
              break;
            }
            case 4:{
              std::cout << "[RUNNER] Resumiendo musica." << '\n';
              musica.resumir();
              break;
            }
            case 5:{
              std::cout << "[RUNNER] Parando musica." << '\n';
              musica.parar();
              break;
            }
            case 7:{
              std::cout << "[RUNNER] Iniciando desplazador de texto." << '\n';
              tm->iniciar();
              break;
            }
            case 8:{
              t->modoDisplay();
              break;
            }
            case 9:{
              Sprite s;
              t->modoAtaque(new Ataque(1, NULL, NULL, false, s, 1000, 5000, 1000, 1000, 100, 250, 200));
              break;
            }
            case 11:{
              continuar = false;
              break;
            }
          }
          mn->setVisible(false);
        }
      }

      /*
        if (evento.key.keysym.sym == SDLK_UP){
          continuar = false;
        }else if (evento.key.keysym.sym == SDLK_LEFT){
          std::cout << "[RUNNER] Reproduciendo sonido intro." << '\n';
          intro.reproducir();
        }else if (evento.key.keysym.sym == SDLK_RIGHT){
          std::cout << "[RUNNER] Reproduciendo musica." << '\n';
          musica.reproducir();
        }else if (evento.key.keysym.sym == SDLK_1){
          std::cout << "[RUNNER] Pausando musica." << '\n';
          musica.pausar();
        }else if (evento.key.keysym.sym == SDLK_2){
          std::cout << "[RUNNER] Resumiendo musica." << '\n';
          musica.resumir();
        }else if (evento.key.keysym.sym == SDLK_3){
          std::cout << "[RUNNER] Parando musica." << '\n';
          musica.parar();
        }else if (evento.key.keysym.sym == SDLK_5){
          std::cout << "[RUNNER] Iniciando desplazador de texto." << '\n';
          tm->iniciar();
        }else if (evento.key.keysym.sym == SDLK_6){
          std::cout << "[RUNNER] Cambiando de modo." << '\n';
          Sprite s;
          t->modoAtaque(new Ataque(1, NULL, NULL, false, s, 1000, 5000, 1000, 1000, 100, 250, 200));
        }
        else if (evento.key.keysym.sym == SDLK_7){
          std::cout << "[RUNNER] Cambiando de modo." << '\n';
          Sprite s;
          t->modoDisplay();
        }else if (evento.key.keysym.sym == SDLK_8){
          bp->setVisible(true);
          std::cout << "[RUNNER] Ingrese el nuevo valor para la barra: ";
          int val;
          cin >> val;
          bp->setPorcentaje(val);
        }else if (evento.key.keysym.sym == SDLK_9){
          std::cout << "[RUNNER] Entrando a menu..." << '\n';
          mn->setVisible(true);
          cout << "[MENU] Menú retornó valor: " << mn->trap() << endl;
          mn->setVisible(false);
        }
      }

      if (evento.type == SDL_QUIT) {
        continuar = false;
      }
*/
      if (!continuar) {
        SDL_WaitEvent(&evento);
      }
    }


  }

  std::cout << "[RUNNER] Cerrando todo y saliendo..." << '\n';
  vivo = false;

  TTF_Quit();
  Mix_CloseAudio();
  SDL_Quit();

  return 0;
}

void Runner::playIntro(){
  Sonido intro("./assets/sonidos/intro.wav");

  Imagen* fond = new Imagen("./assets/screens/cargando.png");
  Escenario e;
  e.setFondo(*fond);
  pantalla->setEscenario(&e);
  thread refresher (&Runner::iniciarRefresher, this);
  refresher.detach();
  //this_thread::sleep_for(chrono::milliseconds(3000));


  fond = new Imagen("./assets/screens/blank.png");
  e.setFondo(*fond);
  //this_thread::sleep_for(chrono::milliseconds(1000));


  fond = new Imagen("./assets/screens/IntroTitle.png");
  e.setFondo(*fond);
  intro.reproducir();
  //this_thread::sleep_for(chrono::milliseconds(5000));
}

void Runner::iniciarRefresher(){
  while (vivo) {
    pantalla->refrescar();
    this_thread::sleep_for(chrono::milliseconds(30));
  }

}

Runner::~Runner(){
  vivo = false;
}
