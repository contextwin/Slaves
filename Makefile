Slaves-0.1: main.c
	$(CC) -Wall -O3 -o Slaves main.c image.c menue1.c common.c font.c -lX11 -lImlib2
