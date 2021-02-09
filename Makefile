# *-* Makefile *-*

HELIOS=C:/Users/Keegan/Documents/lib/helios

include=-I $(HELIOS)/.. -I $(HELIOS)

lib=-L lib -l opengl32 -l glew32 -l glew32s -l freetype -l pthread -l ws2_32 -l gdi32

CC=gcc
CFLAGS=$(include) -D DEBUG

SOURCES := $(wildcard *.c)

OBJECTS := $(patsubst %.c,obj/%.o,$(SOURCES))

default: $(OBJECTS)
	$(CC) -o bin/Test obj/*.o $(HELIOS)/obj/*.o $(lib)

clean:
	rm obj/*

obj/%.o: %.c Makefile
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJECTS:.o=.d)