#ifndef _RUNNER_H
#define _RUNNER_H


#include <vector>
using namespace std;
#include <string>
using namespace std;

class Pantalla;
class Menu;
class Ataque;
class Enemigo;

class Runner {
  private:
    int init=  1;

    Pantalla * pantalla=  NULL;

    bool vivo;

    vector<Menu*> menus;


  public:
    Runner();

    void playIntro();

    void iniciarRefresher();

    int run();

    Menu * cargarMenu(string nombre);

    vector<Ataque> cargarAtaques(string nombre);

    vector<string> cargarDialogo(string nombre);

    Enemigo * cargarEnemigo(string nombre);

    void crearSave();

    void guardarSave(string nNombre, int nivel);

    void iniciarPartida(string nombreJugador, int nivel);

    void gameOver();

    void gameWon();

    ~Runner();

};
#endif
