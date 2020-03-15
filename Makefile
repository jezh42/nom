#==========================================
#  Makefile: makefile for nom
#    Jeremy Hamann (jhamann42@gmail.com)
#  Last Modified: 2020/03/15
#==========================================

CC=gcc
CFLAGS=-O -Wall

all: nom

nom: nom.c nom.h
	$(CC) $(CFLAGS) -o nom nom.c -lncurses

clean:
	rm -f nom

distclean: clean
