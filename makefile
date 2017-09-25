runTest.out: main.o Ataque.o Escenario.o Espacio.o Imagen.o Pantalla.o Prop.o Proyectil.o Runner.o Sprite.o Texto.o Audio.o Sonido.o Musica.o ElementoGUI.o DesplazadorTexto.o HUD.o Tablero.o TextManager.o BarraProgreso.o Menu.o Soul.o Enemigo.o Batalla.o
	g++ -g -lX11 -pthread -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer main.o Ataque.o Escenario.o Espacio.o Imagen.o Pantalla.o Prop.o Proyectil.o Runner.o Sprite.o Texto.o Audio.o Sonido.o Musica.o ElementoGUI.o DesplazadorTexto.o HUD.o Tablero.o TextManager.o BarraProgreso.o Menu.o Soul.o Enemigo.o Batalla.o -o runTest.out

main.o: main.cpp
	g++ -g -c main.cpp

Ataque.o: Ataque.h Ataque.cpp
	g++ -g -c Ataque.cpp

BarraProgreso.o: BarraProgreso.h BarraProgreso.cpp
	g++ -g -c BarraProgreso.cpp

Batalla.o: Batalla.h Batalla.cpp
	g++ -g -c Batalla.cpp

ElementoGUI.o: ElementoGUI.h ElementoGUI.cpp
	g++ -g -c ElementoGUI.cpp

Enemigo.o: Enemigo.h Enemigo.cpp
	g++ -g -c Enemigo.cpp

Escenario.o: Escenario.h Escenario.cpp
	g++ -g -c Escenario.cpp

Espacio.o: Espacio.h Espacio.cpp
	g++ -g -c Espacio.cpp

HUD.o: HUD.h HUD.cpp
	g++ -g -c HUD.cpp

Imagen.o: Imagen.h Imagen.cpp
	g++ -g -c Imagen.cpp

Menu.o: Menu.h Menu.cpp
	g++ -g -c Menu.cpp

Pantalla.o: Pantalla.h Pantalla.cpp
	g++ -g -c Pantalla.cpp

Prop.o: Prop.h Prop.cpp
	g++ -g -c Prop.cpp

Proyectil.o: Proyectil.h Proyectil.cpp
	g++ -g -c Proyectil.cpp

Runner.o: Runner.h Runner.cpp
	g++ -g -c Runner.cpp

Sprite.o: Sprite.h Sprite.cpp
	g++ -g -c Sprite.cpp

Tablero.o: Tablero.h Tablero.cpp
	g++ -g -c Tablero.cpp

Texto.o: Texto.h Texto.cpp
	g++ -g -c Texto.cpp

Audio.o: Audio.h Audio.cpp
	g++ -g -c Audio.cpp

Sonido.o: Sonido.h Sonido.cpp
	g++ -g -c Sonido.cpp

Musica.o: Musica.h Musica.cpp
	g++ -g -c Musica.cpp

DesplazadorTexto.o: DesplazadorTexto.h DesplazadorTexto.cpp
	g++ -g -c DesplazadorTexto.cpp

TextManager.o: TextManager.h TextManager.cpp
	g++ -g -c TextManager.cpp

Soul.o: Soul.h Soul.cpp
	g++ -g -c Soul.cpp

clean:
	rm -rf *.o
