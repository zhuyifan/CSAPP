CC = gcc
CFLAGS = -pthread

all: client

csapp.o: csapp.c csapp.h
	$(CC) $(CFLAGS) -c csapp.c

client.o: client.c csapp.h 
	$(CC) $(CFLAGS) -c client.c

client: client.o csapp.o
	$(CC) $(CFLAGS) client.o csapp.o -o client

clean: 
	rm -f *.o client