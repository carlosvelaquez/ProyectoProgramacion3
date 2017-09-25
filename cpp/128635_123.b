class BarraProgreso
!!!133371.cpp!!!	BarraProgreso()
  SDL_Surface* superficie = SDL_CreateRGBSurface(SDL_HWSURFACE, anchura, altura, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
  colorFondo = SDL_MapRGB(superficie->format, 0x40, 0x40, 0x40);
  colorProgreso = SDL_MapRGB(superficie->format, 0x16, 0xFE, 0x07);
  SDL_FreeSurface(superficie);

  porcentaje = 100;
  porcentajeMax = 100;
  visible  = false;
!!!133499.cpp!!!	BarraProgreso(in nPorcentaje : float, in nPorcentajeMax : float)
  SDL_Surface* superficie = SDL_CreateRGBSurface(SDL_HWSURFACE, anchura, altura, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
  colorFondo = SDL_MapRGB(superficie->format, 0x40, 0x40, 0x40);
  colorProgreso = SDL_MapRGB(superficie->format, 0x16, 0xFE, 0x07);
  SDL_FreeSurface(superficie);

  porcentaje = nPorcentaje;
  porcentajeMax = nPorcentajeMax;
  visible  = false;
!!!133627.cpp!!!	BarraProgreso(in nPorcentaje : float, in nPorcentajeMax : float, in nFondo : Uint32, in nProgreso : Uint32)
  colorFondo = nFondo;
  colorProgreso = nProgreso;

  porcentaje = nPorcentaje;
  porcentajeMax = nPorcentajeMax;
  visible  = false;
!!!133755.cpp!!!	getColorFondo() : Uint32
  return colorFondo;
!!!133883.cpp!!!	getColorProgreso() : Uint32
  return colorProgreso;
!!!134011.cpp!!!	getPorcentaje() : float
  return porcentaje;
!!!134139.cpp!!!	getPorcentajeMax() : float
  return porcentajeMax;
!!!134267.cpp!!!	isVisible() : bool
  return visible;
!!!134395.cpp!!!	setColorFondo(in nFondo : Uint32) : void
  colorFondo = nFondo;
!!!134523.cpp!!!	setColorProgreso(in nProgreso : Uint32) : void
  colorProgreso = nProgreso;
!!!134651.cpp!!!	setPorcentaje(in nPorcentaje : float) : void
  porcentaje = nPorcentaje;
!!!134779.cpp!!!	setPorcentajeMax(in nPorcentajeMax : float) : void
  porcentajeMax = nPorcentajeMax;
!!!134907.cpp!!!	setVisible(in nVisible : bool) : void
  visible = nVisible;
!!!135035.cpp!!!	toSuperficie() : SDL_Surface
  if (visible) {
    SDL_Surface* superficie = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 480, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);

    SDL_Rect offset1;
    offset1.x = 0;
    offset1.y = 0;
    offset1.h = altura;
    offset1.w = anchura;
    SDL_FillRect(superficie, &offset1, colorFondo);

    SDL_Rect offset;
    offset.x = 0;
    offset.y = 0;
    offset.h = altura;
    offset.w = (anchura)*(porcentaje/porcentajeMax);
    SDL_FillRect(superficie, &offset, colorProgreso);

    return superficie;
  }else{
    return NULL;
  }
!!!135163.cpp!!!	refrescar() : bool
  std::cout << "[BarraProgreso] Refrescando..." << '\n';
