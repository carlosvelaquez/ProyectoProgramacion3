class Musica
!!!151547.cpp!!!	Musica(in nRuta : string)
  ruta = nRuta;
  cargar();
!!!152187.cpp!!!	cargar() : bool
  musica = Mix_LoadMUS(ruta.c_str());

  if (musica == NULL) {
    std::cout << "[MUSICA] Error al cargar musica de " << ruta << '\n';
    cargado = false;
  }else{
    cargado = true;
  }

  return cargado;
!!!152059.cpp!!!	reproducir() : bool
  if (Mix_PlayMusic(musica, -1) == -1) {
    std::cout << "[MUSICA] Error al reproducir musica cargada de " << ruta << '\n';
    return false;
  }

  return true;
!!!151675.cpp!!!	pausar() : bool
  if (Mix_PlayingMusic() == 0) {
    std::cout << "[MUSICA] Orden de pausa recibida, pero no hay musica reproduciendose." << '\n';
  }else{
    if (Mix_PausedMusic() == 1) {
      std::cout << "[MUSICA] Orden de pausa recibida, pero la musica ya está pausada." << '\n';
    }else{
      Mix_PauseMusic();
      return true;
    }
  }

  return false;
!!!151803.cpp!!!	resumir() : bool
  if (Mix_PausedMusic() == 1) {
    Mix_ResumeMusic();
    return true;
  }else{
    std::cout << "[MUSICA] Orden de resumir recibida, pero no hay musica pausada." << '\n';
  }

  return false;
!!!151931.cpp!!!	parar() : bool
  if (Mix_HaltMusic() == 0) {
    return true;
  }

  return false;
!!!152315.cpp!!!	verificar() : bool
  Mix_Music* m = NULL;
  m = Mix_LoadMUS(ruta.c_str());

  if (m != NULL) {
    Mix_FreeMusic(m);
    return true;
  }else{
    return false;
  }
!!!152443.cpp!!!	identificar() : string
  return string("Musica cargada de " + ruta);
!!!152571.cpp!!!	liberar() : void
  if (musica) {
    Mix_FreeMusic(musica);
  }else{
    cout << "[MUSICA] Se trató de liberar musica que ya había sido liberada.";
  }
!!!152699.cpp!!!	~Musica()
  Mix_FreeMusic(musica);
