CC = gcc
CFLAGS = -Wall -Wextra -pedantic
LDFLAGS = -L. -ltest

all: main

main: main.o libtest.a
	$(CC) $(CFLAGS) -o main main.o $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

libtest.a: test.o timer.o
	ar rcs libtest.a test.o timer.o

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

timer.o: timer.c
	$(CC) $(CFLAGS) -c timer.c

clean:
	rm -f main libtest.a *.o