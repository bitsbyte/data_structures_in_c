CC = gcc
CPP = g++
INCLUDES=-I../ar -I../bt 
all: test_heap

test_heap: test_heap.c heap.h 
	$(CPP) $(INCLUDES) -o $@ $^ -g -Wno-write-strings 

clean:
	rm test_heap
