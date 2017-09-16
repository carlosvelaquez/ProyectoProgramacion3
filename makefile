#runTest: main.o Ataque.o AtaqueJugador.o Batalla.o Boton.o BotonAccion.o ControladorInputs.o ElementoGUI.o ElementoMenu.o Enemigo.o Escenario.o Espacio.o HUD.o Imagen.o Label.o MedidorAtaque.o Menu.o MostradorTexto.o Pantalla.o Prop.o Proyectil.o Runner.o Sprite.o Tablero.o Texto.o
	#g++ -pthread -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer main.o Ataque.o AtaqueJugador.o Batalla.o Boton.o BotonAccion.o ControladorInputs.o ElementoGUI.o ElementoMenu.o Enemigo.o Escenario.o Espacio.o HUD.o Imagen.o Label.o MedidorAtaque.o Menu.o MostradorTexto.o Pantalla.o Prop.o Proyectil.o Runner.o Sprite.o Tablero.o Texto.o -o runTest

runTest.out: main.o Ataque.o Escenario.o Espacio.o Imagen.o Pantalla.o Prop.o Proyectil.o Runner.o Sprite.o Texto.o Audio.o Sonido.o Musica.o ElementoGUI.o AtaqueJugador.o DesplazadorTexto.o HUD.o Tablero.o TextManager.o
	g++ -g -lX11 -pthread -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer main.o Ataque.o Escenario.o Espacio.o Imagen.o Pantalla.o Prop.o Proyectil.o Runner.o Sprite.o Texto.o Audio.o Sonido.o Musica.o ElementoGUI.o AtaqueJugador.o DesplazadorTexto.o HUD.o Tablero.o TextManager.o -o runTest.out

main.o: main.cpp
	g++ -g -c main.cpp

Ataque.o: Ataque.h Ataque.cpp
	g++ -g -c Ataque.cpp

AtaqueJugador.o: AtaqueJugador.h AtaqueJugador.cpp
	g++ -g -c AtaqueJugador.cpp

#Batalla.o: Batalla.h Batalla.cpp
	#g++ -c Batalla.cpp

#Boton.o: Boton.h Boton.cpp
	#g++ -c Boton.cpp

#BotonAccion.o: BotonAccion.h BotonAccion.cpp
	#g++ -c BotonAccion.cpp

#ControladorInputs.o: ControladorInputs.h ControladorInputs.cpp
	#g++ -c ControladorInputs.cpp

ElementoGUI.o: ElementoGUI.h ElementoGUI.cpp
	g++ -g -c ElementoGUI.cpp

#ElementoMenu.o: ElementoMenu.h ElementoMenu.cpp
	#g++ -c ElementoMenu.cpp

#Enemigo.o: Enemigo.h Enemigo.cpp
#	g++ -c Enemigo.cpp

#Escenario.o Espacio.o HUD.o Imagen.o Label.o MedidorAtaque.o Menu.o MostradorTexto.o Pantalla.o Prop.o Proyectil.o Runner.o Sprite.o Tablero.o Texto.o

Escenario.o: Escenario.h Escenario.cpp
	g++ -g -c Escenario.cpp

Espacio.o: Espacio.h Espacio.cpp
	g++ -g -c Espacio.cpp

HUD.o: HUD.h HUD.cpp
	g++ -c HUD.cpp

Imagen.o: Imagen.h Imagen.cpp
	g++ -g -c Imagen.cpp

#Label.o: Label.h Label.cpp
	#g++ -c Label.cpp

#MedidorAtaque.o: MedidorAtaque.h MedidorAtaque.cpp
	#g++ -c MedidorAtaque.cpp

#Menu.o: Menu.h Menu.cpp
	#g++ -c Menu.cpp

#MostradorTexto.o: MostradorTexto.h MostradorTexto.cpp
	#g++ -c MostradorTexto.cpp

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

clean:
	rm -rf *.o
