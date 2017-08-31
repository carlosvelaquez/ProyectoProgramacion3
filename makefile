run: texto.h texto.cpp main.cpp
	g++ texto.cpp main.cpp -lSDL -lSDL_image -lSDL_ttf -o run -g
