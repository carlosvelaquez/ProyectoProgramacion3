#include "Enemigo.h"

Enemigo::Enemigo(int nAtaque, int nDefensa, int nHP, string nNombre, Sprite nSprite, Sonido nSonidoDialogo, vector<Ataque> nAtaques, int nCantidadAtaques, vector<string> nDialogo, int nFlinch, int nVelocidadFlinch){
  ataque = nAtaque;
  defensa = nDefensa;
  hp = nHP;
  nombre = nNombre;
  sprite = nSprite;
  ataques = nAtaques;
  cantidadAtaques = nCantidadAtaques;
  dialogo = nDialogo;
  flinch = nFlinch;
  velocidadFlinch = nVelocidadFlinch;
}

int Enemigo::getAtaque(){
  return ataque;
}

int Enemigo::getDefensa(){
  return defensa;
}

int Enemigo::getHP(){
  return hp;
}

string Enemigo::getNombre(){
  return nombre;
}

Sprite Enemigo::getSprite(){
  return sprite;
}

Sonido Enemigo::getSonidoDialogo(){
  return sonidoDialogo;
}

vector<Ataque> Enemigo::getAtaques(){
  return ataques;
}

int Enemigo::getCantidadAtaques(){
  cantidadAtaques = ataques.size();
  return cantidadAtaques;
}

vector<string> Enemigo::getDialogo(){
  return dialogo;
}

int Enemigo::getFlinch(){
  return flinch;
}

int Enemigo::getVelocidadFlinch(){
  return velocidadFlinch;
}

void Enemigo::setAtaque(int nAtaque){
  ataque = nAtaque;
}

void Enemigo::setDefensa(int nDefensa){
  defensa = nDefensa;
}

void Enemigo::setHP(int nHP){
  hp = nHP;
}

void Enemigo::setNombre(string nNombre){
  nombre = nNombre;
}

void Enemigo::setSprite(Sprite nSprite){
  sprite = nSprite;
}

void Enemigo::setSonidoDialogo(Sonido nSonidoDialogo){
  sonidoDialogo = nSonidoDialogo;
}

void Enemigo::setAtaques(vector<Ataque> nAtaques){
  ataques = nAtaques;
  cantidadAtaques = ataques.size();
}

void Enemigo::setDialogo(vector<string> nDialogo){
  dialogo = nDialogo;
}

void Enemigo::setFlinch(int nFlinch){
    flinch = nFlinch;
}

void Enemigo::setVelocidadFlinch(int nVelocidadFlinch){
  velocidadFlinch = nVelocidadFlinch;
}

/*SDL_Surface* Enemigo::toSuperficie(){
  return sprite.toSuperficie();
}

bool Enemigo::refrescar(){

}*/



Enemigo::~Enemigo(){
}
