CPP = g++
all: test_ewd 

test_ewd: test_ewd.cpp directed_edge.h directed_edge.cpp edge_weighted_digraph.h edge_weighted_digraph.cpp
	$(CPP) -o $@ $^

clean:
	rm test_ewd 
