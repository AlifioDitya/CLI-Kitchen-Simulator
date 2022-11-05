CC=gcc
TARGET=main

all:
	$(CC) src/modules/inventory/inventory.c src/modules/liststatik/liststatik.c src/modules/makanan/makanan.c src/modules/menu/menu.c src/modules/peta/peta.c src/modules/point/point.c src/modules/prioqueuetime/prioqueuetime.c src/modules/simulator/simulator.c src/modules/string/string.c src/modules/time/time.c src/modules/word-machine/charmachine.c src/modules/word-machine/wordmachine.c src/main.c -o $(TARGET)
