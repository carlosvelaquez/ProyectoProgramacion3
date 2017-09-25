class Sprite
!!!163067.cpp!!!	Sprite()
  Imagen nFuente("./assets/souls.png");
  fuente = nFuente;
  //altura = fuente.getAltura();
  //anchura = fuente.getAnchura();
!!!163195.cpp!!!	Sprite(in nImagenFuente : string)
  Imagen nFuente(nImagenFuente);
  fuente = nFuente;
  //altura = fuente.getAltura();
  //anchura = fuente.getAnchura();
!!!163323.cpp!!!	Sprite(in nFuente : Imagen)
  fuente = nFuente;
  //altura = fuente.getAltura();
  //anchura = fuente.getAnchura();
!!!163451.cpp!!!	Sprite(in nFuente : Imagen, inout nClip : SDL_Rect)
  fuente = nFuente;
  clip = nClip;
!!!163579.cpp!!!	getFuente() : Imagen
  return fuente;
!!!163707.cpp!!!	getClip() : SDL_Rect
  return clip;
!!!163835.cpp!!!	setFuente(in nFuente : Imagen) : void
  fuente = nFuente;
!!!163963.cpp!!!	setClip(inout nClip : SDL_Rect) : void
  clip = nClip;
!!!164091.cpp!!!	setClip(in x : int, in y : int) : void
  SDL_Rect nClip;
  nClip.x = x;
  nClip.y = y;

  clip = &nClip;
!!!164219.cpp!!!	toSuperficie() : SDL_Surface
  return fuente.toSuperficie();
!!!164347.cpp!!!	~Sprite()
  //delete clip;
  //delete superficie;
