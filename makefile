CC = g++
CFLAGS =-I.
DEPS = record.h llist.h

%.o: ui.cpp llist.cpp record.h llist.h
	g++ -DDEBUGMODE -c ui.cpp llist.cpp $(CFLAGS)

record: ui.o llist.o
	g++ -o ui ui.o llist.o -I -pedantic-errors.
