PROG = test

all: $(PROG)

CC = gcc
# Hint for FLAG values come from dpkg-buildflags etc.
CPPFLAGS:=-D_FORTIFY_SOURCE=2
CFLAGS:=-g -Og -Wall
LDFLAGS:=-Wl,-z,relro

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $* $*.c

clean:
	-rm $(PROG)

distclean: clean

.PHONY: all clean distclean
# vim: set ts=8 noet:
