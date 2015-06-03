CC = g++
CFLAGS = -Wall
LDFLAGS = -lm

all : run

run : Main.o Account.o Id.o
	$(CC) $(CFLAGS) Id.o Account.o Main.o $(LDFLAGS) -o run

Id.o : Id.cpp Id.h
	$(CC) $(CFLAGS) -c Id.cpp

Account.o : Account.cpp Account.h Id.h
	$(CC) $(CFLAGS) -c Account.cpp

Main.o : Main.cpp Account.h
	$(CC) $(CFLAGS) -c Main.cpp

clean:
	rm run Id.o Account.o Main.o
