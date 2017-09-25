class Sonido
!!!159227.cpp!!!	Sonido()
  ruta = "./assets/sonidos/ui.wav";
  cargar();
!!!159355.cpp!!!	Sonido(in nRuta : string)
  ruta = nRuta;
  cargar();
!!!159483.cpp!!!	reproducir() : bool
  if (Mix_PlayChannel(-1, sonido, 0) == -1) {
    std::cout << "[SONIDO] Error al reproducir sonido cargado de " << ruta << '\n';
    return false;
  }

  return true;
!!!159611.cpp!!!	cargar() : bool
  sonido = Mix_LoadWAV(ruta.c_str());

  if (sonido == NULL) {
    std::cout << "[SONIDO] Error al cargar sonido de " << ruta << '\n';
    cargado = false;
    return false;
  }else{
    std::cout << "[SONIDO] Sonido cargado exitosamente de " << ruta << '\n';
  }

  cargado = true;
  return true;
!!!159739.cpp!!!	parar() : bool
  if (Mix_HaltChannel(-1) == 0) {
    return true;
  }

  return false;
!!!159867.cpp!!!	verificar() : bool
  Mix_Chunk* s = NULL;
  s = Mix_LoadWAV(ruta.c_str());

  if (s != NULL) {
    Mix_FreeChunk(s);
    return true;
  }else{
    return false;
  }
!!!159995.cpp!!!	identificar() : string
  return string("Sonido cargado de " + ruta);
!!!160123.cpp!!!	liberar() : void
  if (sonido) {
    Mix_FreeChunk(sonido);
  }else{
    cout << "[SONIDO] Se trató de liberar un sonido que ya había sido liberado.";
  }
!!!160251.cpp!!!	~Sonido()
  Mix_FreeChunk(sonido);
