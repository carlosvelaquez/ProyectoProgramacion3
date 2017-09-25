class Texto
!!!169339.cpp!!!	Texto()
  texto = "Placeholder";
  size = 20;
  wrap = 50;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  superficies.clear();
  refrescar();
  recargarFont();
!!!169467.cpp!!!	Texto(in nTexto : string)
  texto = nTexto;
  size = 20;
  wrap = 50;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  superficies.clear();
  refrescar();
  recargarFont();
!!!169595.cpp!!!	Texto(in nTexto : string, in nSize : int)
  texto = nTexto;
  size = nSize;
  wrap = 50;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  superficies.clear();
  refrescar();
  recargarFont();
!!!169723.cpp!!!	Texto(in nTexto : string, in nSize : int, in nWrap : int)
  texto = nTexto;
  size = nSize;
  wrap = nWrap;
  color = {255, 255, 255};
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  superficies.clear();
  refrescar();
  recargarFont();
!!!169851.cpp!!!	Texto(in nTexto : string, in nSize : int, in nWrap : int, in nColor : SDL_Color)
  texto = nTexto;
  size = nSize;
  wrap = nWrap;
  color = nColor;
  rutaFont = "./assets/fonts/DTM-Mono.ttf";
  superficies.clear();
  refrescar();
  recargarFont();
!!!169979.cpp!!!	Texto(in nTexto : string, in nSize : int, in nWrap : int, in nColor : SDL_Color, in nRutaFont : string)
  texto = nTexto;
  size = nSize;
  wrap = nWrap;
  color = nColor;
  rutaFont = nRutaFont;
  superficies.clear();
  refrescar();
  recargarFont();
!!!170107.cpp!!!	getTexto() : string
  return texto;
!!!170235.cpp!!!	getSize() : int
  return size;
!!!170363.cpp!!!	getLength() : int
  return length;
!!!170491.cpp!!!	getWrap() : int
  return wrap;
!!!170619.cpp!!!	getColor() : SDL_Color
  return color;
!!!170747.cpp!!!	getFont() : TTF_Font
  return font;
!!!170875.cpp!!!	toSuperficie() : SDL_Surface
  recargarFont();
  refrescar();

  SDL_Surface* superficie = TTF_RenderText_Solid(font, texto.c_str(), color);
  TTF_CloseFont(font);
  return superficie;
!!!171003.cpp!!!	setTexto(in nTexto : string) : void
  texto = nTexto;
!!!171131.cpp!!!	setSize(in nSize : int) : void
  size = nSize;
  refrescar();
!!!171259.cpp!!!	setWrap(in nWrap : int) : void
  wrap = nWrap;
  refrescar();
!!!171387.cpp!!!	setColor(in nColor : SDL_Color) : void
  color = nColor;
  refrescar();
!!!171515.cpp!!!	cargarFont(in nRutaFont : string) : void
  rutaFont = nRutaFont;
  recargarFont();
  refrescar();
!!!171643.cpp!!!	refrescar() : bool
  length = texto.length();
  altura = size;
  anchura = (size*.75)*length;

!!!171771.cpp!!!	recargarFont() : bool
  font = TTF_OpenFont(rutaFont.c_str(), size);

  if (font) {
    //std::cout << "[TEXTO] Font cargada exitosamente de " << rutaFont << '\n';
    return true;
  }

  std::cout << "[TEXTO] Error al cargar font de " << rutaFont << '\n';
  return false;
!!!172027.cpp!!!	~Texto()
  refrescar();

  /*for (int i = 0; i < superficies.size(); i++) {
    SDL_FreeSurface(superficies[i]);
  }*/
  //TTF_CloseFont(font);
