CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic -lm
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g
EXEC = tetris
FTEMPO = *~ *.o *.gch
DIRH = -I Headers

all: tetris

tetris: Sources/*.c
	$(CC) $(CFLAGS) $(DIRH) -o $@ $^

clean:
	$(RM) $(EXEC) $(FTEMPO)