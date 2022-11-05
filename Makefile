#CC=gcc
#TARGET=main

#all:
#	$(CC) src/modules/inventory/inventory.c src/modules/liststatik/liststatik.c src/modules/makanan/makanan.c src/modules/menu/menu.c src/modules/peta/peta.c src/modules/point/point.c src/modules/prioqueuetime/prioqueuetime.c src/modules/simulator/simulator.c src/modules/string/string.c src/modules/time/time.c src/modules/word-machine/charmachine.c src/modules/word-machine/wordmachine.c src/main.c -o $(TARGET)

# -*- MakeFile -*-

all: main

main: liststatik.o makanan.o menu.o peta.o point.o simulator.o string.o time.o charmachine.o wordmachine.o main.o
	gcc liststatik.o makanan.o menu.o peta.o point.o simulator.o string.o time.o charmachine.o wordmachine.o main.o -o main

liststatik.o: src/modules/liststatik/liststatik.c
	gcc -c src/modules/liststatik/liststatik.c

makanan.o: src/modules/makanan/makanan.c
	gcc -c src/modules/makanan/makanan.c

menu.o: src/modules/menu/menu.c
	gcc -c src/modules/menu/menu.c

peta.o: src/modules/peta/peta.c
	gcc -c src/modules/peta/peta.c

point.o: src/modules/point/point.c
	gcc -c src/modules/point/point.c

simulator.o: src/modules/simulator/simulator.c
	gcc -c src/modules/simulator/simulator.c

string.o: src/modules/string/string.c
	gcc -c src/modules/string/string.c

time.o: src/modules/time/time.c
	gcc -c src/modules/time/time.c

charmachine.o: src/modules/word-machine/charmachine.c
	gcc -c src/modules/word-machine/charmachine.c

wordmachine.o: src/modules/word-machine/wordmachine.c
	gcc -c src/modules/word-machine/wordmachine.c

main.o: src/main.c
	gcc -c src/main.c