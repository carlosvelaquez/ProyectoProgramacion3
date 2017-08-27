#include "SDL/SDL.h"
#include <string>

using namespace std;

SDL_Surface* cargarImagen(string);
void aplicarSuperficie(int, int, SDL_Surface*, SDL_Surface*);

int main(){
  //Declarar el tamaño de la pantalla
  const int pWidth = 640;
  const int pHeight = 480;
  const int pBpp = 32;

  //Inicializar SDL, abortar si algo sale mal
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
    return 1;
  }

  //Superficies
  SDL_Surface* pantalla = NULL;
  SDL_Surface* fondo = NULL;
  SDL_Surface* soul = NULL;

  //Inicializar pantalla, abortar si algo sale mal
  pantalla = SDL_SetVideoMode(pWidth, pHeight, pBpp, SDL_SWSURFACE);
  if (pantalla == NULL) {
    return 1;
  }

  //Ponerle nombre a la pantalla
  SDL_WM_SetCaption("Progratale Pre-Alpha v0.1", NULL);

  //Cargar Imágenes
  fondo = cargarImagen("./assets/fondo.bmp");
  soul = cargarImagen("./assets/soul.bmp");

  //Aplicar imagenes a pantalla
  aplicarSuperficie(0, 0, fondo, pantalla);
  aplicarSuperficie(50, 50, soul, pantalla);

  //Actualizar, abortar si algo sale mal
  if (SDL_Flip(pantalla) == -1) {
    return 1;
  }

  //Pausa
  SDL_Delay(2000);

  //Liberar superficies
  SDL_FreeSurface(soul);
  SDL_FreeSurface(fondo);

  //Parar SDL
  SDL_Quit();
  return 0;
}

SDL_Surface* cargarImagen(string nombreArchivo){
  //Imagen temporal
  SDL_Surface* imagenCargada = NULL;

  //Imagen optimizada
  SDL_Surface* imagenOptimizada = NULL;

  //Cargar la Imagen
  imagenCargada = SDL_LoadBMP(nombreArchivo.c_str());

  //Verificar si se cargo la imagen
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
