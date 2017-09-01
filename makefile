run: Texto.h Texto.cpp mainold.cpp
	g++ Texto.cpp mainold.cpp -lSDL -lSDL_image -lSDL_ttf -o run -g
