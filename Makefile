#The makefile for gbdt on petuum

OBJS = sededir
CC = g++
GCC = gcc
DEBUG = -g
CFLAGS = -std=c++11 -Wall
#LFLAGS = -Wall $(DEBUG)

all: $(OBJS)

test: test.cpp
	$(CC) $(CFLAGS) test.cpp -o test
readbst: readbst.cpp
	$(CC) $(CFLAGS) readbst.cpp -o readbst
sededir: serial_deserial_dirtreenode.c
	$(GCC) serial_deserial_dirtreenode.c -o sededir

clean:
	\rm $(OBJS) $(BIN)
