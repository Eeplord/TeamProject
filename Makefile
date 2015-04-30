CC = g++
CFLAGS = -Wall
LDFLAGS = -lm

all : run

run : Main.o Account.o
	$(CC) $(CFLAGS) Account.o Main.o $(LDFLAGS) -o run

Account.o : Account.cpp Account.h
	$(CC) $(CFLAGS) -c Account.cpp

Main.o : Main.cpp Account.h
	$(CC) $(CFLAGS) -c Main.cpp

clean:
	rm run Account.o Main.o
