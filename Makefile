# -*- MakeFile -*-

# all: main

# main:
# 	gcc src/main.c src/modules/menu/menu.c src/modules/string/string.c src/modules/word-machine/charmachine.c src/modules/word-machine/wordmachine.c src/modules/simulator/simulator.c src/modules/peta/peta.c src/modules/time/time.c src/modules/point/point.c src/modules/liststatik/liststatik.c src/modules/makanan/makanan.c -o src/main.exe

# all: main clean

# driver_peta: peta.o time.o
# 	gcc src/modules/peta/driver_peta.c -o src/modules/peta/driver_peta.exe
	
# main: main.o
# 	gcc main.o menu.o string.o charmachine.o wordmachine.o simulator.o peta.o time.o point.o liststatik.o makanan.o -o src/main.exe

# clean:
# 	rm -rf *.o

# main.o: src/main.c menu.o
# 	gcc -c src/main.c

# menu.o: src/modules/menu/menu.c wordmachine.o string.o simulator.o peta.o liststatik.o
# 	gcc -c src/modules/menu/menu.c

# string.o: src/modules/string/string.c wordmachine.o
# 	gcc -c src/modules/string/string.c

# charmachine.o: src/modules/word-machine/charmachine.c
# 	gcc -c src/modules/word-machine/charmachine.c

# wordmachine.o: src/modules/word-machine/wordmachine.c charmachine.o
# 	gcc -c src/modules/word-machine/wordmachine.c

# simulator.o: src/modules/simulator/simulator.c point.o string.o
# 	gcc -c src/modules/simulator/simulator.c

# peta.o: src/modules/peta/peta.c simulator.o time.o
# 	gcc -c src/modules/peta/peta.c

# time.o: src/modules/time/time.c 
# 	gcc -c src/modules/time/time.c

# point.o: src/modules/point/point.c
# 	gcc -c src/modules/point/point.c

# liststatik.o: src/modules/liststatik/liststatik.c makanan.o
# 	gcc -c src/modules/liststatik/liststatik.c

# makanan.o: src/modules/makanan/makanan.c time.o point.o string.o peta.o
# 	gcc -c src/modules/makanan/makanan.c

CC = gcc

ifdef OS
	TARGETS = $(patsubst "%", %,$(shell forfiles /s /m *main.c /c "cmd /c echo @relpath")) $(patsubst "%", %,$(shell forfiles /s /m driver_*.c /c "cmd /c echo @relpath"))
	INCS = $(patsubst "%", %,$(shell forfiles /s /m *.h /c "cmd /c echo @relpath"))
	SRCS = $(filter-out $(TARGETS), $(patsubst "%", %,$(shell forfiles /s /m *.c /c "cmd /c echo @relpath")))
else
	ifeq ($(shell uname), Linux)
		TARGETS = ./src/main.c $(shell find . -name 'driver_*.c')
		INCS = $(filter-out $(EXCLUDE_INC), $(shell find . -name '*.h'))
		SRCS = $(filter-out $(EXCLUDE_SRC), $(filter-out $(TARGETS), $(shell find . -name '*.c')))
	endif
endif

# TARGETS = ./src/main.c $(shell find . -name 'driver_*.c')
# INCS = $(filter-out $(EXCLUDE_INC), $(shell find . -name '*.h'))
# SRCS = $(filter-out $(EXCLUDE_SRC), $(filter-out $(TARGETS), $(shell find . -name '*.c')))

.PHONY: clean echoes

all: $(addsuffix .exe, $(basename $(TARGETS)))

$(addsuffix .exe, $(basename $(TARGETS))): $(SRCS)
	$(CC) -o $@ $(SRCS) $(addsuffix .c, $(basename $@))

echoes:
	@echo "TARGET files: $(basename $(TARGETS))"  
	@echo "INC files: $(INCS)"  
	@echo "SRC files: $(SRCS)"
	@echo "OBJ files: $(OBJS)"