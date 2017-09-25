class Runner
!!!157563.cpp!!!	Runner()
  pantalla = new Pantalla(480, 640);
  vivo = true;
!!!157947.cpp!!!	run() : int
  bool continuar = true;

  if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
    std::cout << "[RUNNER] Error al inicializar SDL." << '\n';
  }

  if (TTF_Init() == -1) {
    std::cout << "[RUNNER] Error al inicializar TTF." << '\n';
  }

  if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
    std::cout << "[RUNNER] Error al inicializar audio." << '\n';
    return 1;
  }

  std::cout << "[RUNNER] Cargando assets..." << '\n';

  Imagen* fond = new Imagen("./assets/screens/IntroMenu.png");
  Escenario eMenu;
  Menu* mn = cargarMenu("intro");
  Soul* s = new Soul();

  eMenu.setFondo(*fond);
  eMenu.setHUD(new HUD());

  eMenu.getHUD()->addElemento(mn);
  mn->setVisible(true);

  Sonido sonidoIntro("./assets/sonidos/intro.wav");
  Musica musicaMenu("./assets/musica/menu.wav");

  std::cout << "[RUNNER] Assets cargados." << '\n';
  std::cout << "[RUNNER] Iniciando intro..." << '\n';
  playIntro();

  musicaMenu.reproducir();
  pantalla->setEscenario(&eMenu);
  SDL_Event evento;

  SDL_PumpEvents();
  while (SDL_PollEvent(&evento)) {
  }

  while (continuar) {
    switch (mn->trap()) {
      case 0:{
        std::cout << "[RUNNER] Entrando a creación de save." << '\n';
        crearSave();
        pantalla->setEscenario(&eMenu);
        break;
      }
      case 1:{
        string sSave = "SOUL";
        iniciarPartida(sSave, 1);
        break;
      }
      case 2:{
        bool salirControles = false;
        std::cout << "[RUNNER] Entrando a controles." << '\n';
        Escenario eControles;
        eControles.setFondo(Imagen("./assets/screens/controles.png"));
        pantalla->setEscenario(&eControles);

        SDL_PumpEvents();
        while (SDL_PollEvent(&evento)) {
        }
        //SDL_FlushEvent(SDL_KEYDOWN);

        while (!salirControles) {
          while (SDL_PollEvent(&evento)) {
            if (evento.type = SDL_KEYDOWN) {
              switch (evento.key.keysym.sym) {
                case SDLK_z:{
                  salirControles = true;
                  break;
                }
              }
            }
          }

          if (!salirControles) {
            this_thread::sleep_for(chrono::milliseconds(100));
          }else{
            pantalla->setEscenario(&eMenu);

          }
        }
        break;
      }
      case 3:{
        std::cout << "[RUNNER] Saliendo del menú principal." << '\n';
        continuar = false;
        break;
      }
    }

    SDL_PumpEvents();
    while (SDL_PollEvent(&evento)) {
    }

    if (continuar) {
      SDL_WaitEvent(&evento);
    }
  }

  std::cout << "[RUNNER] Cerrando todo y saliendo..." << '\n';
  vivo = false;
  this_thread::sleep_for(chrono::milliseconds(1000));

  TTF_Quit();
  Mix_CloseAudio();
  SDL_Quit();

  return 0;
!!!157691.cpp!!!	playIntro() : void
  Escenario e;
  Imagen* fond = new Imagen("./assets/screens/cargando.png");
  e.setFondo(*fond);
  pantalla->setEscenario(&e);

  thread refresher (&Runner::iniciarRefresher, this);
  refresher.detach();
  this_thread::sleep_for(chrono::milliseconds(10));

  fond = new Imagen("./assets/screens/blank.png");
  e.setFondo(*fond);
  this_thread::sleep_for(chrono::milliseconds(1000));

  Musica introMus("./assets/musica/intro.wav");
  Sonido intro("./assets/sonidos/ui.wav");
  Sonido intro2("./assets/sonidos/intro.wav");

  fond = new Imagen("./assets/screens/intro.png");
  e.setFondo(*fond);
  this_thread::sleep_for(chrono::milliseconds(1000));
  Tablero* t = new Tablero();
  t->setVisible(true);
  t->setPosicionY(460-t->getAltura());

  Texto text("Hace mucho tiempo, hubo un joven muy iluso que entro a estudiar Ingenieria en Sistemas.");
  text.setWrap(47);
  text.setPosicionX(0);
  text.setPosicionY(0);

  TextManager* tm = new TextManager(&text, 25, &intro, 70);
  tm->setPosicionX(15);
  tm->setPosicionY(15);
  e.setHUD(new HUD());

  t->addElemento(tm);
  e.getHUD()->addElemento(t);
  introMus.reproducir();
  tm->iniciar();

  bool saltar = false;
  Uint8* tecla = SDL_GetKeyState(NULL);

  while (tm->isActivo()) {
    SDL_PumpEvents();

    if (tecla[SDLK_x]){
      saltar = true;
      tm->setVelocidad(25);
      tm->setMute(true);
    }else{
      saltar = false;
      tm->setVelocidad(100);
      tm->setMute(false);
      this_thread::sleep_for(chrono::milliseconds(100));
    }
  }

  if (!saltar) {
    this_thread::sleep_for(chrono::milliseconds(3000));
  }

  text.setTexto("Pero al entrar a la universidad y llegar a  Programacion II, se dio cuenta de que talvezhabia tomado una mala decision.");
  text.setWrap(44);

  tm->reconstruir(&text, 25, &intro, 70);
  tm->setPosicionX(15);
  tm->setPosicionY(15);
  tm->iniciar();

  saltar = false;

  while (tm->isActivo()) {
    SDL_PumpEvents();

    if (tecla[SDLK_x]){
      saltar = true;
      tm->setVelocidad(25);
      tm->setMute(true);
    }else{
      saltar = false;
      tm->setVelocidad(100);
      tm->setMute(false);
      this_thread::sleep_for(chrono::milliseconds(100));
    }
  }

  if (!saltar) {
    this_thread::sleep_for(chrono::milliseconds(3000));
  }

  t->setVisible(false);
  introMus.parar();

  fond = new Imagen("./assets/screens/blank.png");
  e.setFondo(*fond);
  this_thread::sleep_for(chrono::milliseconds(1000));

  fond = new Imagen("./assets/screens/IntroTitle.png");
  e.setFondo(*fond);
  intro2.reproducir();
  this_thread::sleep_for(chrono::milliseconds(5000));
!!!157819.cpp!!!	iniciarRefresher() : void
  while (vivo) {
    pantalla->refrescar();
    this_thread::sleep_for(chrono::milliseconds(30));
  }
!!!158075.cpp!!!	cargarMenu(in nombre : string) : Menu
  fstream archivo;
  Menu* m = new Menu();

  string ruta = "./scripts/menus/";
  ruta += nombre;
  ruta += ".txt";

  archivo.open(ruta.c_str());

  if (!archivo) {
    std::cout << "[RUNNER] Error al abrir menu en " << ruta << '\n';
    delete m;
    exit(1);
  }

  int tipo, posX, posY, wrap, size;
  int aR, aG, aB, iR, iG, iB;

  archivo >> tipo;
  archivo >> posX;
  archivo >> posY;
  archivo >> wrap;
  archivo >> aR;
  archivo >> aG;
  archivo >> aB;
  archivo >> iR;
  archivo >> iG;
  archivo >> iB;
  archivo >> size;

  unsigned char r1 = aR;
  unsigned char g1 = aG;
  unsigned char b1 = aB;
  unsigned char r2 = iR;
  unsigned char g2 = iG;
  unsigned char b2 = iB;

  //SDL_Color a = {aR, aG, aB};
  //SDL_Color i = {iR, iG, iB};

  SDL_Color a = {r1, g1, b1};
  SDL_Color i = {r2, g2, b2};

  string s;
  getline(archivo, s);

  m->setTipo(tipo);
  m->setWrap(wrap);
  m->setColorActivo(a);
  m->setColorInactivo(i);
  m->setPosicionX(posX);
  m->setPosicionY(posY);

  while (!archivo.eof()) {
    Texto t;
    //archivo >> t;
    getline(archivo, s);

    t.setTexto(s);
    t.setSize(size);
    m->addElemento(t);
  }

  archivo.close();
  m->chop();
  return m;
!!!158203.cpp!!!	cargarAtaques(in nombre : string) : vector<Ataque>
  fstream archivo;
  vector<Ataque> ataquesCargados;

  string ruta = "./scripts/ataques/";
  ruta += nombre;
  ruta += ".txt";

  archivo.open(ruta.c_str());

  if (!archivo) {
    std::cout << "[RUNNER] Error al abrir ataque en " << ruta << '\n';
    exit(1);
  }

  string buffer;
  getline(archivo, buffer);
  int cantidadAtaques = stoi(buffer);

  for (size_t i = 0; i < cantidadAtaques; i++) {
    getline(archivo, buffer);
    int cantidadProyectiles = stoi(buffer);
    string delimitador = ",";

    int** posiciones = new int*[cantidadProyectiles];
    for (int i = 0; i < cantidadProyectiles; i++) {
      posiciones[i] = new int[2];
    }

    for (int i = 0; i < cantidadProyectiles; i++) {
      getline(archivo, buffer);
      posiciones[i][0] = stoi(buffer.substr(0, buffer.find(delimitador)));
      buffer.erase(0, buffer.find(delimitador) + delimitador.length());
      posiciones[i][1] = stoi(buffer);
    }

    int** velocidades = new int*[cantidadProyectiles];
    for (int i = 0; i < cantidadProyectiles; i++) {
      velocidades[i] = new int[2];
    }

    for (int i = 0; i < cantidadProyectiles; i++) {
      getline(archivo, buffer);
      velocidades[i][0] = stoi(buffer.substr(0, buffer.find(delimitador)));

      buffer.erase(0, buffer.find(delimitador) + delimitador.length());
      velocidades[i][1] = stoi(buffer);
    }

    getline(archivo, buffer);
    bool aleatorio;

    if (buffer == "2") {
      aleatorio = true;
    }

    getline(archivo, buffer);
    Sprite sprite(buffer);

    long vida, sleep1, sleep2, sleep3, duracion;
    int w, h;

    getline(archivo, buffer);
    vida = stol(buffer);
    getline(archivo, buffer);
    sleep1 = stol(buffer);
    getline(archivo, buffer);
    sleep2 = stol(buffer);
    getline(archivo, buffer);
    sleep3 = stol(buffer);
    getline(archivo, buffer);
    duracion = stol(buffer);

    getline(archivo, buffer);
    w = stoi(buffer);
    getline(archivo, buffer);
    h = stoi(buffer);

    Ataque a(cantidadProyectiles, posiciones, velocidades, aleatorio, sprite, vida, duracion, sleep1, sleep2, sleep3, w, h);
    ataquesCargados.push_back(a);
  }

  archivo.close();
  return ataquesCargados;
!!!158331.cpp!!!	cargarDialogo(in nombre : string) : vector<string>
  std::cout << nombre << '\n';
  ifstream archivo2;

  string ruta;
  ruta = "./scripts/dialogo/";
  ruta += nombre;
  ruta += ".txt";

  //std::cout << "Ruta: " << ruta << '\n';
  archivo2.open(ruta.c_str(), std::ifstream::in);
  //std::cout << "Intentando abrir archivo..." << '\n';
  //std::cout << "Archivo abierto." << '\n';

  vector<string> nDialogo;

  if (!archivo2) {
    std::cout << "[RUNNER] Error al abrir dialogo en ";//<< ruta << '\n';
    exit(1);
  }

  string buffer;
  //std::cout << "Entrandio" << '\n';

  while(!archivo2.eof()){
    getline(archivo2, buffer);
    //cout << "Linea: " << buffer << endl;
    nDialogo.push_back(buffer);
  }

  //std::cout << "saliendo" << '\n';

  archivo2.close();

  return nDialogo;
!!!158459.cpp!!!	cargarEnemigo(in nombre : string) : Enemigo
  fstream archivo;

  string ruta = "./scripts/enemigos/";
  ruta += nombre;
  ruta += ".txt";

  archivo.open(ruta.c_str());

  if (!archivo) {
    std::cout << "[RUNNER] Error al abrir enemigo en " << ruta << '\n';
    exit(1);
  }

  string buffer;
  string satk, sdef, shp, nomb, rutaSprite, rutaSonido, nNombre, sflinch, svelFlinch;
  int atk, def, hp, flinch, velFlinch;

  getline(archivo, buffer);
  satk = buffer;
  getline(archivo, buffer);
  sdef = buffer;
  getline(archivo, buffer);
  shp = buffer;
  getline(archivo, buffer);
  nomb = buffer;
  getline(archivo, buffer);
  rutaSprite = buffer;
  getline(archivo, buffer);
  rutaSonido = buffer;
  getline(archivo, buffer);
  nNombre = buffer;
  getline(archivo, buffer);
  sflinch = buffer;
  getline(archivo, buffer);
  svelFlinch = buffer;

  archivo.close();

  vector<Ataque> ataques = cargarAtaques(nNombre);
  //std::cout << "Ataques cargados" << '\n';
  vector<string> dialogo = cargarDialogo(nNombre);
  //std::cout << "Hola" << '\n';

  atk = stoi(satk);
  //std::cout << atk << '\n';
  def = stoi(sdef);
  //std::cout << def << '\n';
  hp = stoi(shp);
  //std::cout << hp << '\n';
  flinch = stoi(sflinch);
  //std::cout << flinch << '\n';
  velFlinch = stoi(svelFlinch);
  //std::cout << velFlinch << '\n';

  Enemigo* e = new Enemigo(atk, def, hp, nomb, Sprite(rutaSprite), Sonido(rutaSonido), ataques, ataques.size(), dialogo, flinch, velFlinch);
  //std::cout << "Enemigo generado" << '\n';
  return e;
!!!158587.cpp!!!	crearSave() : void
  SDL_Event evento;
  string nuevoNombre = "";
  Escenario escenario;
  escenario.setFondo(Imagen("./assets/screens/black.png"));
  HUD* hud = new HUD();
  escenario.setHUD(hud);
  Menu* teclado = cargarMenu("teclado");
  hud->addElemento(teclado);

  Texto titulo("Ingresa tu Nombre");
  titulo.setSize(30);
  titulo.setPosicionX(50);
  titulo.setPosicionY(30);
  hud->addElemento(&titulo);

  Texto* nombre = new Texto(nuevoNombre);
  nombre->setSize(20);
  nombre->setPosicionX(50);
  nombre->setPosicionY(420);
  hud->addElemento(nombre);

  pantalla->setEscenario(&escenario);

  bool salir = false;
  teclado->setVisible(true);

  while (!salir) {
    nombre->setTexto(nuevoNombre);
    switch (teclado->trap()) {
      case 0:{
        nuevoNombre += "Q";
        break;
      }
      case 1:{
        nuevoNombre += "W";
        break;
      }
      case 2:{
        nuevoNombre += "E";
        break;
      }
      case 3:{
        nuevoNombre += "R";
        break;
      }
      case 4:{
        nuevoNombre += "T";
        break;
      }
      case 5:{
        nuevoNombre += "Y";
        break;
      }
      case 6:{
        nuevoNombre += "U";
        break;
      }
      case 7:{
        nuevoNombre += "I";
        break;
      }
      case 8:{
        nuevoNombre += "O";
        break;
      }
      case 9:{
        nuevoNombre += "P";
        break;
      }
      case 10:{
        nuevoNombre += "A";
        break;
      }
      case 11:{
        nuevoNombre += "S";
        break;
      }
      case 12:{
        nuevoNombre += "D";
        break;
      }
      case 13:{
        nuevoNombre += "F";
        break;
      }
      case 14:{
        nuevoNombre += "G";
        break;
      }
      case 15:{
        nuevoNombre += "H";
        break;
      }
      case 16:{
        nuevoNombre += "J";
        break;
      }
      case 17:{
        nuevoNombre += "K";
        break;
      }
      case 18:{
        nuevoNombre += "L";
        break;
      }
      case 19:{
        nuevoNombre += "Z";
        break;
      }
      case 20:{
        nuevoNombre += "X";
        break;
      }
      case 21:{
        nuevoNombre += "C";
        break;
      }
      case 22:{
        nuevoNombre += "V";
        break;
      }
      case 23:{
        nuevoNombre += "B";
        break;
      }
      case 24:{
        nuevoNombre += "N";
        break;
      }
      case 25:{
        nuevoNombre += "M";
        break;
      }
      case 27:{
        if (nuevoNombre.size() > 0) {
          nuevoNombre.pop_back();
        }
        break;
      }
      case 29:{
        salir = true;
        break;
      }
    }

    if (!salir){
      SDL_WaitEvent(&evento);
    }
  }

  guardarSave(nuevoNombre, 0);
  iniciarPartida(nuevoNombre, 0);
!!!158715.cpp!!!	guardarSave(in nNombre : string, in nivel : int) : void
  fstream archivo;
  string ruta = "./saves/";
  ruta += nNombre;
  ruta += ".txt";

  archivo.open(ruta.c_str(), fstream::out);

  if (!archivo) {
    std::cout << "[RUNNER] Error al abrir/guardar savefile en " << ruta << '\n';
    exit(1);
  }

  archivo << nivel;
  archivo.close();
!!!158843.cpp!!!	iniciarPartida(in nombreJugador : string, in nivel : int) : void
  Mix_HaltMusic();

  Sonido sonidoUI("./assets/sonidos/ui.wav");
  Sonido suspenso("./assets/sonidos/suspenso.wav");
  Sonido jump("./assets/sonidos/jump.wav");
  Sonido sonidoMalvado("./assets/sonidos/malvado.wav");
  Sonido ropa("./assets/sonidos/ropa.wav");
  Sonido flee("./assets/sonidos/flee.wav");
  Sonido bossName("./assets/sonidos/bossName.wav");
  Sonido hit("./assets/sonidos/hit.wav");
  Sonido sonidoAtaque("./assets/sonidos/ataque.wav");

  Musica musicaBoss1("./assets/musica/boss3.wav");

  SDL_Event evento;
  Escenario escenario;
  escenario.setFondo(Imagen("./assets/screens/black.png"));
  HUD* hud = new HUD();
  escenario.setHUD(hud);
  pantalla->setEscenario(&escenario);

  std::cout << "[RUNNER] Iniciando partida..." << '\n';

  switch (nivel) {
    case 0:{
      suspenso.reproducir();
      this_thread::sleep_for(chrono::milliseconds(6830));

      Tablero* tablero = new Tablero();
      Texto* textoRaw = new Texto(string("???: Umm hey."));
      TextManager* texto = new TextManager(textoRaw, 25, &sonidoUI, 75);
      hud->addElemento(tablero);
      tablero->addElemento(texto);
      tablero->setPosicionY(460-tablero->getAltura());
      tablero->setVisible(true);

      texto->trap();

      textoRaw->setTexto(string("???: Oye, estas bien?"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->trap();

      textoRaw->setTexto(string("* Tu cabeza duele, pero haces un esfuerzo para    levantarte y ver quien te habla."));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->trap();

      Musica musicaTutorial("./assets/musica/tutorial.wav");

      Enemigo* guiaJaguar = cargarEnemigo("tutorial");
      tablero->setVisible(false);

      ropa.reproducir();
      this_thread::sleep_for(chrono::milliseconds(5000));
      escenario.setFondo(Imagen("./assets/screens/batallaTutorial.png"));
      jump.reproducir();

      textoRaw->setTexto(string("???: Hola!"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      tablero->setVisible(true);
      this_thread::sleep_for(chrono::milliseconds(750));

      musicaTutorial.reproducir();
      texto->trap();

      textoRaw->setTexto(string("???: Soy JOSUE, el GUIA JAGUAR!"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->trap();

      textoRaw->setTexto(string("- Parece que te quedaste dormido en esa banca...  Dejame adivinar, Progra 2?"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->trap();

      textoRaw->setTexto(string("- Si, lo se, la ultima semana es bastante dura    El proyecto del INGENIERO OSMAN no es nada facil"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->trap();

      textoRaw->setTexto(string("- Como lo se? Yo tambien estudio SISTEMAS!"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->trap();

      textoRaw->setTexto(string("- Tu eres " + nombreJugador + " no?"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->trap();

      textoRaw->setTexto(string("- Es todo un placer conocerte!"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->trap();

      textoRaw->setTexto(string("- Me caes bien. Ven, te dare algunos tips para    que domines ese proyecto!"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->trap();
      this_thread::sleep_for(chrono::milliseconds(500));

      tablero->setVisible(false);
      escenario.setFondo(Imagen("./assets/screens/black.png"));
      jump.reproducir();
      this_thread::sleep_for(chrono::milliseconds(250));
      tablero->setAltura(80);
      tablero->setPosicionY(tablero->getPosicionY() + 50);

      Tablero* tablero2 = new Tablero();
      Ataque atk = guiaJaguar->getAtaques()[0];
      Ataque* ataque = &atk;
      tablero2->modoAtaque(ataque);
      Soul* soul = new Soul();
      tablero2->setSoul(soul);
      SDL_Rect bounds;

      while (tablero2->isListo() == false) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }

      bounds.w = tablero2->getAnchura();
      bounds.h = tablero2->getAltura();
      soul->setBounds(bounds);
      soul->centrar();

      textoRaw->setTexto(string("Este corazon representa a tu FUERZA DE VOLUNTAD   Es todo aquello que te impulsa a seguir adelante."));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      tablero->setVisible(true);
      tablero2->setVisible(true);
      Imagen black("./assets/screens/black.png");
      tablero2->addElemento(soul);
      hud->addElemento(tablero2);
      Batalla* batallaTutorial = new Batalla(guiaJaguar, black, NULL, NULL);

      thread ejecucion (&Soul::trap, soul);
      ejecucion.detach();

      tablero->setVisible(true);
      jump.reproducir();
      escenario.setFondo(Imagen("./assets/screens/batallaTutorial.png"));

      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));

      texto->setVisible(false);
      textoRaw->setTexto(string("- Vamos, muevete un poco! Has de estar entumecido por dormir ahi."));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));

      texto->setVisible(false);
      textoRaw->setTexto(string("- Mientras mas grande sea tu FUERZA DE VOLUNTAD   mas facil te sera vencer tus obstaculos!"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));

      texto->setVisible(false);
      textoRaw->setTexto(string("- Como haces a tu FUERZA DE VOLUNTAD mas grande?  Con esferas de amistad, por supuesto!"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));

      texto->setVisible(false);
      textoRaw->setTexto(string("- Ten, tengo unas para ti. Agarra todas las que   puedas!"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->setVisible(true);
      texto->iniciar();

      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(1000));

      thread tTablero (&Tablero::activar, tablero2, ataque, guiaJaguar->getAtaque());
      tTablero.detach();
      //tablero2->activar(ataque, guiaJaguar->getAtaque());

      while (soul->getHP() == 100) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }

      ataque->interrumpir();
      Mix_HaltMusic();
      Mix_HaltChannel(-1);
      this_thread::sleep_for(chrono::milliseconds(5000));

      escenario.setFondo(Imagen("./assets/screens/batallaTutorial2.png"));

      texto->setVisible(false);
      textoRaw->setTexto(string("- Ha ha ha"));
      texto->reconstruir(textoRaw, 25, &sonidoMalvado, 150);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));

      texto->setVisible(false);
      textoRaw->setTexto(string("- De verdad que eres muy iluso."));
      texto->reconstruir(textoRaw, 25, &sonidoMalvado, 100);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));

      texto->setVisible(false);
      textoRaw->setTexto(string("- En este mundo NADIE te va a ayudar.             Estas completamente SOLO."));
      texto->reconstruir(textoRaw, 25, &sonidoMalvado, 75);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));

      texto->setVisible(false);
      textoRaw->setTexto(string("- Otro estudiante de SISTEMAS, otro nino tonto    que piensa que puede llegar a ser alguien."));
      texto->reconstruir(textoRaw, 25, &sonidoMalvado, 75);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));

      texto->setVisible(false);
      textoRaw->setTexto(string("- Pero sabes que veo yo?"));
      texto->reconstruir(textoRaw, 25, &sonidoMalvado, 75);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));

      texto->setVisible(false);
      textoRaw->setTexto(string("- COMPETENCIA."));
      texto->reconstruir(textoRaw, 25, &sonidoMalvado, 150);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));


      escenario.setFondo(Imagen("./assets/screens/batallaTutorial3.png"));
      texto->setVisible(false);
      textoRaw->setTexto(string("???: Oigan, que esta pasando ahi?"));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));


      texto->setVisible(false);
      textoRaw->setTexto(string("- Nos vemos!"));
      texto->reconstruir(textoRaw, 25, &sonidoMalvado, 75);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));

      escenario.setFondo(Imagen("./assets/screens/black.png"));
      texto->setVisible(false);
      tablero2->setVisible(false);
      flee.reproducir();
      textoRaw->setTexto(string("* Josue salio corriendo..."));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->setVisible(true);
      texto->iniciar();
      while (texto->isActivo()) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
      this_thread::sleep_for(chrono::milliseconds(3000));

      escenario.setFondo(Imagen("./assets/screens/black.png"));
      jump.reproducir();
      tablero->setVisible(false);
      this_thread::sleep_for(chrono::milliseconds(3000));
      escenario.setFondo(Imagen("./assets/screens/guardando.png"));
      this_thread::sleep_for(chrono::milliseconds(3000));
      escenario.setFondo(Imagen("./assets/screens/black.png"));
      this_thread::sleep_for(chrono::milliseconds(100));
      pantalla->setEscenario(NULL);

      iniciarPartida(nombreJugador, 1);
      break;
    }
    case 1:{
      Imagen screen1 = Imagen("./assets/screens/batallaBoss1.png");
      Imagen screen2 = Imagen("./assets/screens/batallaBoss12.png");
      Imagen screen3 = Imagen("./assets/screens/batallaBoss13.png");

      int atkJugador = 25;
      Soul* soul = new Soul();
      Enemigo* boss1 = cargarEnemigo("boss1");
      Menu* menuBatalla = cargarMenu("batalla");
      Texto* barraJugador = new Texto(" ");
      Texto* barraEnemigo = new Texto(" ");

      barraEnemigo->setAnchura(10);
      barraEnemigo->setPosicionX(60);
      barraEnemigo->setPosicionY(40);
      barraEnemigo->setVisible(false);


      //barraJugador->setAnchura(50);
      barraJugador->setPosicionX(240);
      barraJugador->setPosicionY(400);
      barraJugador->setVisible(false);

      menuBatalla->setPosicionY(430);
      menuBatalla->setPosicionX(15);
      menuBatalla->setPosicionX(50);
      menuBatalla->setVisible(false);

      std::cout << "[RUNNER] Entrando a nivel 1." << '\n';
      this_thread::sleep_for(chrono::milliseconds(2000));
      Tablero* tablero = new Tablero();
      tablero->setVisible(false);
      tablero->setPosicionY(280);
      tablero->setSoul(soul);

      Texto* textoRaw = new Texto(string("* Una semana despues..."));
      TextManager* texto = new TextManager(textoRaw, 25, &sonidoUI, 75);
      texto->setPosicionX(20);
      texto->setPosicionY(440);
      hud->addElemento(texto);
      texto->trap();
      this_thread::sleep_for(chrono::milliseconds(1000));
      texto->setVisible(false);

      texto = new TextManager(textoRaw, 25, &sonidoUI, 75);
      textoRaw->setTexto(string("???: Espero que este listo senor " + nombreJugador + "."));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      hud->addElemento(tablero);
      tablero->addElemento(texto);
      tablero->setVisible(true);
      texto->trap();
      this_thread::sleep_for(chrono::milliseconds(1000));

      jump.reproducir();
      escenario.setFondo(Imagen("./assets/screens/batallaBoss1.png"));
      textoRaw->setTexto(string("- Muestreme de que esta hecho."));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 75);
      texto->trap();
      this_thread::sleep_for(chrono::milliseconds(1000));

      tablero->setVisible(false);

      Texto textoRaw2 = Texto(string("ING. OSMAN MEJIA"));
      textoRaw2.setSize(50);
      DesplazadorTexto* texto2 = new DesplazadorTexto(textoRaw2, &bossName, 250);
      texto2->setPosicionX(70);
      texto2->setPosicionY(325);
      hud->addElemento(texto2);
      texto2->iniciar();
      texto2->setVisible(true);
      this_thread::sleep_for(chrono::milliseconds(9000));
      texto2->setVisible(false);
      musicaBoss1.reproducir();

      tablero->setVisible(true);
      hud->addElemento(menuBatalla);
      textoRaw->setTexto(string("* El ING. OSMAN te observa fijamente."));
      texto->reconstruir(textoRaw, 25, &sonidoUI, 25);
      texto->iniciar();

      Texto* textoRawSec = new Texto(string("123"));
      TextManager* textoSecundario = new TextManager(textoRaw, 25, &sonidoUI, 75);
      tablero->addElemento(textoSecundario);
      textoSecundario->setVisible(false);

      menuBatalla->setVisible(true);
      SDL_PumpEvents();
      while (SDL_PollEvent(&evento)) {}
      SDL_Event evento;
      bool continuar = true;
      Ataque atk = boss1->getAtaques()[0];
      Ataque* ataque = &atk;

      SDL_Rect bounds;

      bounds.w = 200;
      bounds.h = 200;
      soul->setBounds(bounds);
      soul->centrar();
      soul->setVisible(true);

      hud->addElemento(barraEnemigo);
      hud->addElemento(barraJugador);

      while (continuar) {
        int atkNormal = boss1->getAtaque();
        texto->setVisible(true);
        texto->reconstruir(textoRaw, 25, &sonidoUI, 25);
        texto->iniciar();

        SDL_PumpEvents();
        while (SDL_PollEvent(&evento)) {}

        switch (menuBatalla->trap()) {
          case 2:{
            texto->setVisible(false);
            textoRawSec->setTexto(string("ING OSMAN MEJIA - ?? ATK / ?? DEF                 No puedes ni verlo a la cara por los nervios."));
            textoSecundario->setVisible(true);
            textoSecundario->reconstruir(textoRawSec, 25, &sonidoUI, 75);
            textoSecundario->trap();
            textoSecundario->setVisible(false);
            break;
          }
          case 1:{
            texto->setVisible(false);
            textoRawSec->setTexto(string("* Te defenderas durante el siguiente turno        Dano recibido reducido."));
            textoSecundario->setVisible(true);
            textoSecundario->reconstruir(textoRawSec, 25, &sonidoUI, 75);
            textoSecundario->trap();
            boss1->setAtaque(atkNormal*.5);
            textoSecundario->setVisible(false);
            break;
          }
          case 0:{
            this_thread::sleep_for(chrono::milliseconds(500));
            sonidoAtaque.reproducir();
            this_thread::sleep_for(chrono::milliseconds(500));
            hit.reproducir();

            for (size_t i = 0; i < 6; i++) {
              escenario.setFondo(screen2);
              this_thread::sleep_for(chrono::milliseconds(75));
              escenario.setFondo(screen3);
              this_thread::sleep_for(chrono::milliseconds(75));
            }

            escenario.setFondo(screen1);


            boss1->setHP(boss1->getHP() - atkJugador);
            atkJugador += 5;

            barraEnemigo->setTexto(string("HP: " + to_string(boss1->getHP()) + "/250"));
            barraEnemigo->setVisible(true);
            this_thread::sleep_for(chrono::milliseconds(2000));
            barraEnemigo->setVisible(false);

            break;
          }
        }

        if (boss1->getHP() <= 0) {
          cout << "[RUNNER] Boss vencido." << endl;
          continuar = false;
        }


        menuBatalla->setVisible(false);

        tablero->modoAtaque(ataque);
        while (tablero->isListo() == false) {
          this_thread::sleep_for(chrono::milliseconds(100));
        }

        thread tTablero (&Tablero::activar, tablero, ataque, boss1->getAtaque());
        tTablero.detach();
        soul->trap();

        while (ataque->activo) {
          this_thread::sleep_for(chrono::milliseconds(100));
        }

        barraJugador->setTexto(string(nombreJugador + ": " + to_string(soul->getHP()) + "/600"));
        barraJugador->setVisible(true);

        if (soul->getHP() <= 0) {
          cout << "[RUNNER] Jugador vencido." << endl;
          gameOver();
          continuar = false;
        }

        tablero->modoDisplay();
        menuBatalla->setVisible(true);


        if (continuar) {
          SDL_WaitEvent(&evento);
        }
      }

      run();
      pantalla->setEscenario(NULL);
      break;
    }
  }



!!!158971.cpp!!!	gameOver() : void
  this_thread::sleep_for(chrono::milliseconds(1000));
  Escenario escenario;
  escenario.setFondo(Imagen("./assets/screens/gameOver.png"));

  pantalla->setEscenario(&escenario);
  Musica gameOv("./assets/musica/gameOver.wav");
  gameOv.reproducir();
  this_thread::sleep_for(chrono::milliseconds(7000));
  run();
!!!159099.cpp!!!	~Runner()
  Mix_HaltMusic();
  vivo = false;
