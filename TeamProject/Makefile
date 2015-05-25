CC = g++
CFLAGS = -Wall
LDFLAGS = -lm

all : run

run : Main.o Account.o Storage.o
	$(CC) $(CFLAGS) Storage.o Account.o Main.o $(LDFLAGS) -o run

Storage.o : Storage.cpp Storage.h Account.h
	$(CC) $(CFLAGS) -c Storage.cpp

Account.o : Account.cpp Account.h
	$(CC) $(CFLAGS) -c Account.cpp

Main.o : Main.cpp Account.h Storage.h
	$(CC) $(CFLAGS) -c Main.cpp

clean:
	rm run Storage.o Account.o Main.o
