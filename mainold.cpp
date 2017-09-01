#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "texto.h"
#include <string>
#include <iostream>

using namespace std;

bool init();
bool cargarSuperficies();
bool refrescarPantalla();
void limpiarTodo();
SDL_Surface* cargarImagen(string);
void aplicarSuperficie(int, int, SDL_Surface*, SDL_Surface*);
void aplicarSuperficie(SDL_Surface*, SDL_Surface*, int, int);
void aplicarSuperficie(SDL_Surface*, SDL_Surface*, int);
void aplicarSuperficie(Texto, SDL_Surface*, int, int);

//Declarar el tamaño de la pantalla
const int pWidth = 640;
const int pHeight = 480;
const int pBpp = 32;

//Declarar superficies
SDL_Surface* pantalla = NULL;
SDL_Surface* fondo = NULL;
SDL_Surface* logoTextS = NULL;
SDL_Surface* logoBackS = NULL;
SDL_Surface* tituloS = NULL;
SDL_Surface* mensajeS = NULL;

/*//Declarar fuentes
TTF_Font* fontDialogo = NULL;
TTF_Font* fontTitulo = NULL;
TTF_Font* fontLogo = NULL;
TTF_Font* fontLogoBack = NULL;*/

//Textos
SDL_Color blanco = {255, 255, 255};
SDL_Color grisLogo = {130, 130, 130};

Texto logoText(string("progratAle"), 60, 12, blanco, string("./assets/fonts/MonsterFriendFore.ttf"));
Texto logoBack(string("progratAle"), 60, 12, grisLogo, string("./assets/fonts/MonsterFriendBack.ttf"));
Texto mensaje(string("Esta es una prueba para Progratale v0.1"), 25, 50, blanco, string("./assets/fonts/DTM-Mono.ttf"));
Texto titulo(string("PERMANCE DETERMINADO"), 35, 15, blanco, string("./assets/fonts/DTM-Sans.ttf"));

int main(){
  bool continuar = true;

  if (init() == false) {
    return 1;
  }

  if (cargarSuperficies() == false) {
    return 1;
  }

  SDL_Event evento; //Estructura de evento

  /*logoTextS = TTF_RenderText_Solid(fontLogo, "progratAle", colorLogo);
  logoBackS = TTF_RenderText_Solid(fontLogoBack, "progratAle", colorLogoBack);
  tituloS = TTF_RenderText_Solid(fontTitulo, "Permanece Determinado", colorTitulo);
  mensajeS = TTF_RenderText_Solid(fontDialogo, "Esta es una prueba para Progratale v0.01", colorDialogo);*/

  /*if (logoText == NULL || logoBack == NULL || titulo == NULL || mensaje == NULL) {
    return 1;
  }*/

  /*aplicarSuperficie(logoBack, fondo, .5, .3);
  aplicarSuperficie(logoText, fondo, .5, .3);
  aplicarSuperficie(titulo, fondo, .5, .4);
  aplicarSuperficie(mensaje, fondo, .5, .5);*/


  if (refrescarPantalla() == false) {
    return 1;
  }

  int cont = 0;

  while (continuar) {
    while (SDL_PollEvent(&evento)) {
      if (evento.type = SDL_KEYDOWN) {
        if (evento.key.keysym.sym == SDLK_DOWN) {
          switch (cont) {
            case 0:{
              aplicarSuperficie(pWidth/40, ((pHeight/3)-20), logoBack.toSuperficie(), fondo);
              aplicarSuperficie(pWidth/40, ((pHeight/3)-20), logoText.toSuperficie(), fondo);
              cont++;
            }break;
            case 1:{
                aplicarSuperficie(pWidth/5, (pHeight/2), titulo.toSuperficie(), fondo);
                cont++;
            }break;
            case 2:{
              aplicarSuperficie(pWidth/35, ((pHeight/2)+35), mensaje.toSuperficie(), fondo);
              cont++;
            }break;
          }
          refrescarPantalla();
        }
      }

      if (evento.type == SDL_QUIT) {
        continuar = false;
      }
    }
  }

  limpiarTodo();
  return 0;
}

bool cargarSuperficies(){
  fondo = cargarImagen("./assets/fondo.png");
  /*fontDialogo = TTF_OpenFont("./assets/fonts/DTM-Mono.ttf", 25);
  fontTitulo = TTF_OpenFont("./assets/fonts/DTM-Sans.ttf", 35);
  fontLogo = TTF_OpenFont("./assets/fonts/MonsterFriendFore.ttf", 60);
  fontLogoBack = TTF_OpenFont("./assets/fonts/MonsterFriendBack.ttf", 60);]*/
  //soul = cargarImagen("./assets/soul.bmp");

  /*/if (fontLogo == NULL || fontDialogo == NULL || fontLogoBack == NULL || fontTitulo =aplicarSuperficie(fondo, pantalla, .1, .1);= NULL) {
    return false;
  }*/

  return true;
}

bool init(){
  //Inicializar SDL, abortar si algo sale mal
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
    return false;
  }

  //Inicializar pantalla, abortar si algo sale mal
  pantalla = SDL_SetVideoMode(pWidth, pHeight, pBpp, SDL_SWSURFACE);
  if (pantalla == NULL) {
    return false;
  }

  if( TTF_Init() == -1 )
    {
        return false;
    }

  //Ponerle nombre a la pantalla
  SDL_WM_SetCaption("Progratale Pre-Alpha v0.1", NULL);

  return true;
}

SDL_Surface* cargarImagen(string nombreArchivo){
  //Imagen temporal
  SDL_Surface* imagenCargada = NULL;

  //Imagen optimizada
  SDL_Surface* imagenOptimizada = NULL;

  //Cargar la Imagen
  imagenCargada = IMG_Load(nombreArchivo.c_str());

  //Verificar si se cargo la imagenaplicarSuperficie(fondo, pantalla, .1, .1);
  if (imagenCargada != NULL) {
    //Optimizar imagen
    imagenOptimizada = SDL_DisplayFormat(imagenCargada);

    //Liberar la imagen antigua
    SDL_FreeSurface(imagenCargada);
  }

  return imagenOptimizada;
}

void aplicarSuperficie(int x, int y, SDL_Surface* fuente, SDL_Surface* destino){
  //Crear un rectangulo para contener los offsets
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  //"Blittear" la Superficies
  SDL_BlitSurface(fuente, NULL, destino, &offset);
}

void aplicarSuperficie(SDL_Surface* fuente, SDL_Surface* destino, int porcentajeX, int porcentajeY){
  double x, y;

  x = ((destino->w)*porcentajeX)-((fuente->w)*porcentajeX);
  y = ((destino->h)*porcentajeY)-((fuente->h)*porcentajeY);

  std::cout << x << "," << y << '\n';

  //Crear un rectangulo para contener los offsets
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  //"Blittear" la Superficies
  SDL_BlitSurface(fuente, NULL, destino, &offset);
}

void aplicarSuperficie(Texto fuenteT, SDL_Surface* destino, int porcentajeX, int porcentajeY){
  double x, y;

  x = ((destino->w)*porcentajeX)-((fuenteT.getDimX())*porcentajeX);
  y = ((destino->h)*porcentajeY)-((fuenteT.getDimY())*porcentajeY);

  std::cout << x << "," << y << '\n';

  //Crear un rectangulo para contener los offsets
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  SDL_Surface* fuente = fuenteT.toSuperficie();

  //"Blittear" la Superficies
  SDL_BlitSurface(fuente, NULL, destino, &offset);
}

void aplicarSuperficie(SDL_Surface* fuente, SDL_Surface* destino, int porcentajeXY){
  int x, y;

  x = ((destino->w)*porcentajeXY)-((fuente->w)*porcentajeXY);
  y = ((destino->h)*porcentajeXY)-((fuente->h)*porcentajeXY);

  //Crear un rectangulo para contener los offsets
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  //"Blittear" la Superficies
  SDL_BlitSurface(fuente, NULL, destino, &offset);
}

bool refrescarPantalla(){

  aplicarSuperficie(0, 0, fondo, pantalla);

  //Actualizar, abortar si algo sale mal
  if (SDL_Flip(pantalla) == -1) {
    return false;
  }

  return true;
}

void limpiarTodo(){
  //Liberar superficies
  SDL_FreeSurface(mensajeS);
  SDL_FreeSurface(fondo);
  SDL_FreeSurface(tituloS);
  SDL_FreeSurface(logoBackS);
  SDL_FreeSurface(logoTextS);

  TTF_Quit();

  //Parar SDL
  SDL_Quit();
}
