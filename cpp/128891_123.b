class Batalla
!!!135291.cpp!!!	Batalla(inout nEnemigo : Enemigo, in nFondo : Imagen, inout nMusica : Musica, inout nDecoraciones : Sprite)
  enemigo = nEnemigo;
  fondo = nFondo;
  musica = nMusica;
  decoraciones = nDecoraciones;
!!!136699.cpp!!!	~Batalla()
  if (decoraciones != NULL) {
    delete decoraciones;
  }
!!!135419.cpp!!!	getEnemigo() : Enemigo
  return enemigo;
!!!135547.cpp!!!	getFondo() : Imagen
  return fondo;
!!!135675.cpp!!!	getMusica() : Musica
  return musica;
!!!135803.cpp!!!	getDecoraciones() : Sprite
  return decoraciones;
!!!135931.cpp!!!	isActiva() : bool
  return activa;
!!!136059.cpp!!!	setEnemigo(inout nEnemigo : Enemigo) : void
  enemigo = nEnemigo;
!!!136315.cpp!!!	setMusica(inout nMusica : Musica) : void
  musica = nMusica;
!!!136443.cpp!!!	setDecoraciones(inout nDeco : Sprite) : void
  decoraciones = nDeco;
!!!136571.cpp!!!	setActiva(in nActiva : bool) : void
  activa = nActiva;
