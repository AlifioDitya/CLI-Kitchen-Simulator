#CC=gcc
#TARGET=main

#all:
#	$(CC) src/modules/inventory/inventory.c src/modules/liststatik/liststatik.c src/modules/makanan/makanan.c src/modules/menu/menu.c src/modules/peta/peta.c src/modules/point/point.c src/modules/prioqueuetime/prioqueuetime.c src/modules/simulator/simulator.c src/modules/string/string.c src/modules/time/time.c src/modules/word-machine/charmachine.c src/modules/word-machine/wordmachine.c src/main.c -o $(TARGET)

# -*- MakeFile -*-

all: main clean

main: main.o
	gcc main.o menu.o string.o charmachine.o wordmachine.o simulator.o peta.o time.o point.o liststatik.o makanan.o -o src/main.exe

clean:
	rm -rf *.o

main.o: src/main.c menu.o
	gcc -c src/main.c

menu.o: src/modules/menu/menu.c wordmachine.o string.o simulator.o peta.o liststatik.o
	gcc -c src/modules/menu/menu.c

string.o: src/modules/string/string.c wordmachine.o
	gcc -c src/modules/string/string.c

charmachine.o: src/modules/word-machine/charmachine.c
	gcc -c src/modules/word-machine/charmachine.c

wordmachine.o: src/modules/word-machine/wordmachine.c charmachine.o
	gcc -c src/modules/word-machine/wordmachine.c

simulator.o: src/modules/simulator/simulator.c point.o string.o
	gcc -c src/modules/simulator/simulator.c

peta.o: src/modules/peta/peta.c simulator.o time.o
	gcc -c src/modules/peta/peta.c

time.o: src/modules/time/time.c 
	gcc -c src/modules/time/time.c

point.o: src/modules/point/point.c
	gcc -c src/modules/point/point.c

liststatik.o: src/modules/liststatik/liststatik.c makanan.o
	gcc -c src/modules/liststatik/liststatik.c

makanan.o: src/modules/makanan/makanan.c time.o point.o string.o peta.o
	gcc -c src/modules/makanan/makanan.c