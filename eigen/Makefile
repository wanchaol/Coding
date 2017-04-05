CC = g++
CFLAGS = -std=c++11 -I /usr/local/Cellar/eigen/3.3.3/include/eigen3/ 

#Tell make to make one .out file for each .cpp file found in the current directory
all: $(patsubst %.cc, %.out, $(wildcard *.cc))

#Rule how to create arbitary .out files. 
#First state what is needed for them e.g. additional headers, .cpp files in an include folder...
#Then the command to create the .out file, probably you want to add further options to the g++ call.
%.out: %.cc Makefile
	$(CC) $(CFLAGS) $< -o $@ 
