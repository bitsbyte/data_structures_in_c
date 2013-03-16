CC = gcc
CPP = g++
all: test_symbol_graph test_graph

test_graph: test_graph.cpp graph.h graph.cpp depth_first_search.h depth_first_search.cpp breadth_first_search.h breadth_first_search.cpp cycle.h cycle.cpp two_color.h two_color.cpp
	$(CPP)  -o $@ $^  

test_symbol_graph: test_symbol_graph.cpp symbol_graph.cpp graph.cpp  
	$(CPP) -o $@ $^ -I../ -std=c++0x -g

clean:
	rm test_graph test_symbol_graph
