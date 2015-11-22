h17400
s 00009/00000/00000
d D 1.1 15/10/19 17:39:29 jsc940 1 0
c date and time created 15/10/19 17:39:29 by jsc940
e
u
U
f e 0
t
T
I 1
CC = gcc
CFLAGS =-I.
DEPS = headers.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

headers: ui.o storage.o
	gcc -o ui ui.o storage.o -I.
E 1
