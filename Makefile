# -*- MakeFile -*-

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

.PHONY: clean echoes

all: $(addsuffix .exe, $(basename $(TARGETS)))

liststatik: $(addsuffix .exe, $(basename $(patsubst "%", %,$(shell forfiles /s /m *driver_liststatik.c /c "cmd /c echo @relpath"))))

peta: $(addsuffix .exe, $(basename $(patsubst "%", %,$(shell forfiles /s /m *driver_peta.c /c "cmd /c echo @relpath"))))

time: $(addsuffix .exe, $(basename $(patsubst "%", %,$(shell forfiles /s /m *driver_time.c /c "cmd /c echo @relpath"))))

word-machine: $(addsuffix .exe, $(basename $(patsubst "%", %,$(shell forfiles /s /m *driver_fwm.c /c "cmd /c echo @relpath"))))

simulator: $(addsuffix .exe, $(basename $(patsubst "%", %,$(shell forfiles /s /m *driver_simulator.c /c "cmd /c echo @relpath"))))

undoredo: $(addsuffix .exe, $(basename $(patsubst "%", %,$(shell forfiles /s /m *driver_ur.c /c "cmd /c echo @relpath"))))

prioqueue: $(addsuffix .exe, $(basename $(patsubst "%", %,$(shell forfiles /s /m *driver_prioqueue.c /c "cmd /c echo @relpath"))))

main: $(addsuffix .exe, $(basename $(patsubst "%", %,$(shell forfiles /s /m *main.c /c "cmd /c echo @relpath"))))

pengolahan: $(addsuffix .exe, $(basename $(patsubst "%", %,$(shell forfiles /s /m *driver_pengolahan.c /c "cmd /c echo @relpath"))))

$(addsuffix .exe, $(basename $(TARGETS))): $(SRCS)
	$(CC) -o $@ $(SRCS) $(addsuffix .c, $(basename $@))

echoes:
	@echo "TARGET files: $(basename $(TARGETS))"  
	@echo "INC files: $(INCS)"  
	@echo "SRC files: $(SRCS)"
	@echo "OBJ files: $(OBJS)"