CPP = g++
all: test_digraph	test_dfs test_bfs test_directed_cycle test_topological

test_digraph: test_digraph.cpp digraph.h digraph.cpp 
	$(CPP)  -o $@ $^  

test_dfs: test_dfs.cpp digraph.h digraph.cpp depth_first_search.h depth_first_search.cpp
	$(CPP) -o $@ $^

test_bfs: test_bfs.cpp digraph.h digraph.cpp breadth_first_search.h breadth_first_search.cpp
	$(CPP) -o $@ $^

test_directed_cycle: test_directed_cycle.cpp digraph.h digraph.cpp directed_cycle.h directed_cycle.cpp
	$(CPP) -o $@ $^

test_topological: test_topological.cpp digraph.h digraph.cpp topological.h topological.cpp directed_cycle.h directed_cycle.cpp symbol_digraph.h symbol_digraph.cpp
	$(CPP) -o $@ $^ -std=c++0x -I../../

clean:
	rm test_digraph test_dfs test_bfs test_directed_cycle test_topological
