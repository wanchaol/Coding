CC = g++
CFLAGS = -std=c++11 -Wall
#LFLAGS = -Wall $(DEBUG)

all: %.out

%.out: %.cc
	$(CC) $(CFLAGS) $<

clean:
	rm -f $.out
