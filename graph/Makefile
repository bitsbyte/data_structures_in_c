CC = gcc
CPP = g++
all: test_graph

test_graph: test_graph.cpp graph.h graph.cpp depth_first_search.h depth_first_search.cpp breadth_first_search.h breadth_first_search.cpp
	$(CPP)  -o $@ $^  

clean:
	rm test_graph
