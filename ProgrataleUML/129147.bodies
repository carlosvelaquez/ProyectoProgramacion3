class Imagen
!!!147067.cpp!!!	Imagen()
  ruta = "./assets/soul.png";
  cargada = recargar();
!!!147195.cpp!!!	Imagen(in nRuta : string)
  ruta = nRuta;
  cargada = recargar();
!!!147707.cpp!!!	recargar() : bool
  SDL_Surface* imagenCargada = NULL;
  imagenCargada = IMG_Load(ruta.c_str());

  if (imagenCargada != NULL) {
    altura = imagenCargada->h;
    anchura = imagenCargada->w;
    superficie = SDL_DisplayFormat(imagenCargada);

    SDL_FreeSurface(imagenCargada);
    cargada = true;

  }else{
    std::cout << "[IMAGEN] Imagen en " << ruta << "no pudo ser cargada." << '\n';
    cargada = false;

    altura = 0;
    anchura = 0;
    return false;
  }

  return true;
!!!147835.cpp!!!	getAnchura() : int
  return anchura;
!!!147963.cpp!!!	getAltura() : int
  return altura;
!!!148091.cpp!!!	toSuperficie() : SDL_Surface
  return superficie;
!!!148219.cpp!!!	~Imagen()
  if (superficie != NULL) {
    //SDL_FreeSurface(superficie);
    //std::cout << "[IMAGEN] Imagen cargada de " << ruta << " destruida." << '\n';
  }
