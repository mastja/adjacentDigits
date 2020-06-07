# macro tells which compiler to use
CC = g++

# macro says using c++11 standard
CFLAGS = -std=c++11 -c

# run "make all" to run adjacentDigits
all: adjacentDigits

# make the adjacentDigits program
adjacent: adjacentDigits.o
	$(CC) adjacentDigits.o -o digits

adjacentDigits.o:
	$(CC) $(CFLAGS) adjacentDigits.cpp

clean:
	rm *.o
	rm adjacentDigits