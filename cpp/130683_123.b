class Soul
!!!160379.cpp!!!	Soul()
  velocidad = 5;
  velocidadBlink = 150;
  duracionBlink = 1000;
  visible = false;
  sprite = Sprite("./assets/soul.png");
  altura = 16;
  anchura = 16;
  hp = 600;
!!!160507.cpp!!!	getSprite() : Sprite
  return sprite;
!!!160635.cpp!!!	getVelocidad() : int
  return velocidad;
!!!160763.cpp!!!	getVelocidadBlink() : int
  return velocidadBlink;
!!!160891.cpp!!!	getDuracionBlink() : long
  return duracionBlink;
!!!161147.cpp!!!	setSprite(in nSprite : Sprite) : void
  sprite = nSprite;
!!!161275.cpp!!!	setVelocidad(in nVelocidad : int) : void
  velocidad = nVelocidad;
!!!161787.cpp!!!	trap() : void
  SDL_Event ev;
  salirTrap = false;
  visible = true;
  Uint8* tecla = SDL_GetKeyState(NULL);

  while(!salirTrap){
    //delete[] tecla;
    SDL_PumpEvents();
    /*while (SDL_PollEvent(&ev)) {
      //std::cout << "[SOUL] Entrando a trap..." << '\n';
      if (ev.type = SDL_KEYDOWN) {
        switch (ev.key.keysym.sym) {
          case SDLK_UP:{
            mover(1);
            break;
          }
          case SDLK_DOWN:{
            mover(2);
            break;
          }
          case SDLK_LEFT:{
            mover(3);
            break;
          }
          case SDLK_RIGHT:{
            mover(4);
            break;
          }
          case SDLK_0:{
            salir = true;
            break;
          }
          case SDLK_9:{
            blink();
            break;
          }
        }
      }
    }*/

    if (tecla[SDLK_UP]) {
      mover(1);
    }
    if (tecla[SDLK_DOWN]) {
      mover(2);
    }
    if (tecla[SDLK_LEFT]) {
      mover(3);
    }
    if (tecla[SDLK_RIGHT]) {
      mover(4);
    }
    if (tecla[SDLK_0]) {
      salirTrap = true;
    }
    if (tecla[SDLK_9]) {
      blink();
      this_thread::sleep_for(chrono::milliseconds(200));
    }

    if (!salirTrap) {
      this_thread::sleep_for(chrono::milliseconds(30));
    }

  }

  visible = false;
!!!161915.cpp!!!	blink() : void
  thread blinker (&Soul::comenzarBlink, this);
  blinker.detach();
!!!162043.cpp!!!	comenzarBlink() : void
  visible = false;

  for (size_t i = 0; i < duracionBlink; i++) {
    if (i%velocidadBlink == 0) {
      if (visible) {
        visible = false;
      }else{
        visible = true;
      }
    }
    this_thread::sleep_for(chrono::milliseconds(1));
  }

  visible = true;
!!!162171.cpp!!!	mover(in direccion : int) : void
  switch (direccion) {
    case 1:{
      if (posicionY - velocidad > 0) {
        posicionY -= velocidad;
      }
      break;
    }
    case 2:{
      if (posicionY + velocidad < bounds.h - altura) {
        posicionY += velocidad;
      }
      break;
    }
    case 3:{
      if (posicionX - velocidad > 0) {
        posicionX -= velocidad;
      }
      break;
    }
    case 4:{
      if (posicionX + velocidad < bounds.w - anchura) {
        posicionX += velocidad;
      }
      break;
    }
  }
!!!162299.cpp!!!	terminarTrap() : void
  salirTrap = true;
!!!162555.cpp!!!	getBounds() : SDL_Rect
  return bounds;
!!!162683.cpp!!!	setBounds(in nBounds : SDL_Rect) : void
  bounds = nBounds;
!!!162427.cpp!!!	centrar() : void
  posicionX = (bounds.w/2) - anchura;
  posicionY = (bounds.h/2) - altura;
!!!161019.cpp!!!	getHP() : int
  return hp;
!!!161659.cpp!!!	setHP(in nHP : int) : void
  hp = nHP;
!!!162811.cpp!!!	toSuperficie() : SDL_Surface
  if (visible) {
    return sprite.toSuperficie();
  }else{
    return NULL;
  }
!!!162939.cpp!!!	refrescar() : bool
  std::cout << "[SOUL] Refrescando..." << '\n';
  return true;
