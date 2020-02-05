Slaves-0.1: main.c
	$(CC) -Wall -O3 -o Slaves-0.1 main.c `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf -lpng
