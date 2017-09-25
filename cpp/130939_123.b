class TextManager
!!!166779.cpp!!!	TextManager(inout texto : Texto, in nMultiplicador : int, inout sonido : Sonido, in velocidad : long)
  desplazadores.clear();
  vector<string> strings;
  strings.clear();

  string s = texto->getTexto();
  int ind = 0;
  int limite;

  while (ind < texto->getTexto().length()) {
    if (texto->getTexto().length() - ind < texto->getWrap()) {
      limite = texto->getTexto().length() - ind;
    }else{
      limite = texto->getWrap();
    }

    int i;
    string str = "";

    for (i = 0; i < limite; i++) {
      if (s[i + ind] == '\n') {
        i++;
        break;
      }
      str += s[i + ind];
    }

    ind += i;
    //std::cout << str << '\n';

    desplazadores.push_back(new DesplazadorTexto(str, sonido, velocidad));
  }

  setVisible(false);
  multiplicador = nMultiplicador;

  setPosicionX(15);
  setPosicionY(15);
!!!166907.cpp!!!	reconstruir(inout texto : Texto, in nMultiplicador : int, inout sonido : Sonido, in velocidad : long) : void
  desplazadores.clear();
  vector<string> strings;
  strings.clear();

  string s = texto->getTexto();
  int ind = 0;
  int limite;

  while (ind < texto->getTexto().length()) {
    if (texto->getTexto().length() - ind < texto->getWrap()) {
      limite = texto->getTexto().length() - ind;
    }else{
      limite = texto->getWrap();
    }

    int i;
    string str = "";

    for (i = 0; i < limite; i++) {
      if (s[i + ind] == '\n') {
        i++;
        break;
      }
      str += s[i + ind];
    }

    ind += i;
    //std::cout << str << '\n';

    desplazadores.push_back(new DesplazadorTexto(str, sonido, velocidad));
  }

  setVisible(false);
  multiplicador = nMultiplicador;
  setPosicionX(15);
  setPosicionY(15);
!!!167035.cpp!!!	getMultiplicador() : int
  return multiplicador;
!!!167163.cpp!!!	setMultiplicador(in nMultiplicador : int) : void
  multiplicador = nMultiplicador;
!!!167419.cpp!!!	getPosicionX() : int
  if (desplazadores.size() > 0) {
    return desplazadores[0]->getPosicionX();
  }else{
    return -1;
  }
!!!167547.cpp!!!	getPosicionY() : int
  if (desplazadores.size() > 0) {
    return desplazadores[0]->getPosicionY();
  }else{
    return -1;
  }
!!!167291.cpp!!!	isActivo() : bool
  return activo;
!!!167675.cpp!!!	setPosicionX(in nPos : int) : void
  if (desplazadores.size() > 0) {
    desplazadores[0]->setPosicionX(nPos);
  }
!!!167803.cpp!!!	setPosicionY(in nPos : int) : void
  if (desplazadores.size() > 0) {
    desplazadores[0]->setPosicionY(nPos);
  }
!!!168059.cpp!!!	getDesplazadores() : vector<DesplazadorTexto*>
  return desplazadores;
!!!168187.cpp!!!	setDesplazadores(in nDesplazadores : vector<DesplazadorTexto*>) : void
  desplazadores = nDesplazadores;
!!!168315.cpp!!!	addDesplazador(inout nDesplazador : DesplazadorTexto) : void
  desplazadores.push_back(nDesplazador);
!!!168443.cpp!!!	setVisible(in nVisible : bool) : void
  for (int i = 0; i < desplazadores.size(); i++) {
    desplazadores[i]->setVisible(nVisible);
  }
!!!168955.cpp!!!	trap() : void
  Uint8* tecla = SDL_GetKeyState(NULL);
  bool saltar = false;
  long velocidadOld;

  if (desplazadores.size() > 0) {
    velocidadOld = desplazadores[0]->getVelocidad();
  }else{
    velocidadOld = 100;
  }

  iniciar();

  while (activo) {
    SDL_PumpEvents();

    if (tecla[SDLK_x]){
      saltar = true;
      setVelocidad(25);
      setMute(true);
    }else{
      saltar = false;
      setVelocidad(velocidadOld);
      setMute(false);
      this_thread::sleep_for(chrono::milliseconds(100));
    }
  }

  if (!saltar) {
    this_thread::sleep_for(chrono::milliseconds(3000));
  }
!!!168699.cpp!!!	iniciar() : void
  setVisible(false);
  activo = true;

  thread ejecucion (&TextManager::desplazar, this);
  ejecucion.detach();
!!!168827.cpp!!!	desplazar() : void

  for (int i = 0; i < desplazadores.size(); i++) {
    desplazadores[i]->setPosicionY((i*multiplicador) + desplazadores[0]->getPosicionY());
    desplazadores[i]->setPosicionX(desplazadores[0]->getPosicionX());
    desplazadores[i]->setVisible(true);
    desplazadores[i]->iniciar();

    while (desplazadores[i]->isActivo()) {
      this_thread::sleep_for(chrono::milliseconds(100));
    }
  }

  activo = false;
!!!167931.cpp!!!	setVelocidad(in nVelocidad : long) : void
  for (int i = 0; i < desplazadores.size(); i++) {
    desplazadores[i]->setVelocidad(nVelocidad);
  }
!!!168571.cpp!!!	setMute(in nMute : bool) : void
  for (int i = 0; i < desplazadores.size(); i++) {
    desplazadores[i]->setMute(nMute);
  }
!!!169083.cpp!!!	toSuperficie() : SDL_Surface
  SDL_Surface* superficie = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 480, 32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);

  for (int i = 0; i < desplazadores.size(); i++) {
    if (desplazadores[i]->isVisible()){
      SDL_Surface* super = desplazadores[i]->toSuperficie();
      SDL_Rect offset2;
      offset2.x = desplazadores[i]->getPosicionX();
      offset2.y = desplazadores[i]->getPosicionY();

      SDL_BlitSurface(super, NULL, superficie, &offset2);
      SDL_FreeSurface(super);
    }
  }

  return superficie;
!!!169211.cpp!!!	refrescar() : bool
  return true;
