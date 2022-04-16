CC=g++
CFLAGS=-g -Og
.PHONY:clean
clean:
	rm -rf *.o *.out RandomAverage HalfLife

.PHONY:RandomAverage
RandomAverage:RandomAverage.o Random.h
	$(CC) $(CFLAGS) RandomAverage.o -o RandomAverage
RandomAverage.o:RandomAverage.cpp
	$(CC) $(CFLAGS) -c RandomAverage.cpp
.PHONY:HalfLife
HalfLife:HalfLife.o Random.h
	$(CC) $(CFLAGS) HalfLife.o -o HalfLife
HalfLife.o:HalfLife.cpp
	$(CC) $(CFLAGS) -c HalfLife.cpp

