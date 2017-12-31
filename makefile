CC = g++
CFLAGS = -g

default: Hyperion

Hyperion: dxdt.o main.o
	$(CC) $(CFLAGS) -o Hyperion dxdt.o main.o -lpython2.7

dxdt.o: dxdt.cpp header.h
	$(CC) $(CFLAGS) -c dxdt.cpp 

main.o: main.cpp header.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) count *.o *~


