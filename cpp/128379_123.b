class Proyectil
!!!156027.cpp!!!	Proyectil(in nSprite : Sprite, in posX : int, in posY : int, in velX : int, in velY : int, in vid : long)
  sprite = nSprite;
  posicionX = posX;
  posicionY = posY;
  velocidadX = velX;
  velocidadY = velY;
  anchura = 10;
  altura = 10;
  vida = vid;
!!!156155.cpp!!!	Proyectil(in nSprite : Sprite, in posX : int, in posY : int)
  sprite = nSprite;
  posicionX = posX;
  posicionY = posY;
  velocidadX = 0;
  velocidadY = 0;
  vida = 1000;
!!!156283.cpp!!!	getSprite() : Sprite
  return sprite;
!!!156411.cpp!!!	getVelocidadX() : int
  return velocidadX;
!!!156539.cpp!!!	getVelocidadY() : int
  return velocidadY;
!!!156667.cpp!!!	setSprite(in nSprite : Sprite) : void
  sprite = nSprite;
!!!156795.cpp!!!	setVelocidadX(in velX : int) : void
  velocidadX = velX;
!!!156923.cpp!!!	setVelocidadY(in velY : int) : void
  velocidadY = velY;
!!!157051.cpp!!!	activar() : void
  activo = true;
  thread ejecucion (&Proyectil::ejecutar, this);
  ejecucion.detach();
!!!157179.cpp!!!	ejecutar() : void
  visible = true;

  for (int i = 0; i < vida/50; i++) {
    posicionX += velocidadX;
    posicionY += velocidadY;
    this_thread::sleep_for(chrono::milliseconds(50));
  }

  visible = false;
!!!157307.cpp!!!	toSuperficie() : SDL_Surface
  if (!visible) {
    return NULL;
  }

  return sprite.toSuperficie();
!!!157435.cpp!!!	refrescar() : bool
  return true;
