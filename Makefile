Slaves-0.1: main.c
	$(CC) -Wall -O3 -o Slaves main.c image.c menue.c common.c font.c status.c -lX11 -lImlib2
