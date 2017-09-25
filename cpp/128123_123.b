class Ataque
!!!128123.cpp!!!	Ataque(in nCantidadProyectiles : int, inout nPosiciones : int, inout nVelocidades : int, in nAleatorio : bool, in nSpriteProyectiles : Sprite, in nVidaProyectiles : long, in nDuracion : long, in nSleepProyectiles : long, in nSleepRondas : long, in nSleepInicial : long, in nAnchura : int, in nAltura : int)
  cantidadProyectiles = nCantidadProyectiles;
  posiciones = nPosiciones;
  velocidades = nVelocidades;
  aleatorio = nAleatorio;
  spriteProyectiles = nSpriteProyectiles;
  vidaProyectiles = nVidaProyectiles;
  sleepProyectiles = nSleepProyectiles;
  sleepRondas = nSleepRondas;
  sleepInicial = nSleepInicial;
  duracion = nDuracion;
  anchuraTablero = nAnchura;
  alturaTablero = nAltura;

  proyectilesActivos = new vector<Proyectil*>();
!!!128251.cpp!!!	getCantidadProyectiles() : int
  return cantidadProyectiles;
!!!128379.cpp!!!	getPosiciones() : int
  return posiciones;
!!!128507.cpp!!!	getVelocidades() : int
  return velocidades;
!!!128635.cpp!!!	getPosicionesDecoraciones() : int
  return posicionesDecoraciones;
!!!128763.cpp!!!	isAleatorio() : bool
  return aleatorio;
!!!128891.cpp!!!	getDecoraciones() : Sprite
  return decoraciones;
!!!129147.cpp!!!	getVidaProyectiles() : long
  return vidaProyectiles;
!!!129275.cpp!!!	getDuracion() : long
  return duracion;
!!!129403.cpp!!!	getSleepProyectiles() : long
  return sleepProyectiles;
!!!129531.cpp!!!	getSleepRondas() : long
  return sleepProyectiles;
!!!129659.cpp!!!	getSleepInicial() : long
  return sleepInicial;
!!!129787.cpp!!!	setCantidadProyectiles(in nCantidadProyectiles : int) : void
  cantidadProyectiles = nCantidadProyectiles;
!!!129915.cpp!!!	setPosiciones(inout nPosiciones : int) : void
  posiciones = nPosiciones;
!!!130043.cpp!!!	setVelocidades(inout nVelocidades : int) : void
  velocidades = nVelocidades;
!!!130171.cpp!!!	setDecoraciones(inout nDecoraciones : Sprite) : void
  decoraciones = nDecoraciones;
!!!130299.cpp!!!	setPosicionesDecoraciones(inout nPosicionesDecoraciones : int) : void
  posicionesDecoraciones = nPosicionesDecoraciones;
!!!130427.cpp!!!	setAleatorio(in nAleatorio : bool) : void
  aleatorio = nAleatorio;
!!!130555.cpp!!!	setSpriteProyectiles(in nSpriteProyectiles : Sprite) : void
  spriteProyectiles = nSpriteProyectiles;
!!!130683.cpp!!!	setVidaProyectiles(in nVidaProyectiles : long) : void
  vidaProyectiles = nVidaProyectiles;
!!!130811.cpp!!!	setDuracion(in nDuracion : long) : void
  duracion = nDuracion;
!!!130939.cpp!!!	setSleepProyectiles(in nSleepProyectiles : long) : void
  sleepProyectiles = nSleepProyectiles;
!!!131067.cpp!!!	setSleepRondas(in nSleepRondas : long) : void
  sleepRondas = nSleepRondas;
!!!131195.cpp!!!	setSleepInicial(in nSleepInicial : long) : void
  sleepInicial = nSleepInicial;
!!!131323.cpp!!!	activar() : void
  activo = true;
  thread ejecucion (&Ataque::ejecutar, this);
  ejecucion.detach();

  thread cronom (&Ataque::cronometro, this);
  cronom.detach();
!!!131451.cpp!!!	ejecutar() : void
  while (activo) {
    for (int i = 0; i < cantidadProyectiles; i++) {
      int posX, posY, velX, velY;
      posX = posiciones[i][0];
      posY = posiciones[i][1];
      velX = velocidades[i][0];
      velY = velocidades[i][1];

      Proyectil* p = new Proyectil(spriteProyectiles, posX, posY, velX, velY, vidaProyectiles);
      proyectilesActivos->push_back(p);
      p->activar();
      this_thread::sleep_for(chrono::milliseconds(sleepProyectiles));
    }

    this_thread::sleep_for(chrono::milliseconds(sleepRondas));
  }

  for (int i = 0; i < proyectilesActivos->size(); i++) {
    delete proyectilesActivos->at(i);
  }

  proyectilesActivos->clear();
!!!131707.cpp!!!	interrumpir() : void
  activo = false;
!!!131579.cpp!!!	cronometro() : void
  for (size_t i = 0; i < duracion; i++) {
    this_thread::sleep_for(chrono::milliseconds(1));
  }
  activo = false;
!!!131835.cpp!!!	getAnchuraTablero() : int
  return anchuraTablero;
!!!131963.cpp!!!	getAlturaTablero() : int
  return alturaTablero;
!!!132091.cpp!!!	setAnchuraTablero(in nAnchura : int) : void
  anchuraTablero = nAnchura;
!!!132219.cpp!!!	setAlturaTablero(in nAltura : int) : void
  alturaTablero = nAltura;
!!!132347.cpp!!!	~Ataque()
  /*for (int i = 0; i < cantidadProyectiles; i++) {
  delete[] posiciones;
  delete[] velocidades;
}

delete decoraciones;*/
