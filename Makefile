CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic -lm -lncurses
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g
EXEC = tetris
FTEMPO = *~ *.o
DIRH = Headers
DIRC = Sources

all: mrproper tetris

.PHONY : clean mrproper

tetris: Sources/*.c
	$(CC) $(CFLAGS) -I $(DIRH) -o $@ $^

clean:
	@((cd $(DIRH) && $(MAKE) $@) && (cd $(DIRC) && $(MAKE) $@))

mrproper: clean
	$(RM) $(EXEC)