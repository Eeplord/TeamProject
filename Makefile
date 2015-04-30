CC = g++
CFLAGS = -Wall
LDFLAGS = -lm

all : run

run : main.o account.o
	$(CC) $(CFLAGS) account.o main.o $(LDFLAGS) -o run

account.o : account.cpp account.h
	$(CC) $(CFLAGS) -c account.cpp

main.o : main.cpp account.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm run account.o main.o
