#include "edge_weighted_digraph.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		cout << "usage: test_ewd input_file" << endl;
		return 1;
		//exit(1);
	}
	
	ifstream ifs;
	ifs.open(argv[1]);
	edge_weighted_digraph g(ifs);

	cout << "graph read from file: " << argv[1] << endl;
	cout << g << endl;

	cout << "empty graph: " << endl;
	edge_weighted_digraph g2(4);
	cout << g2 << endl;
	return 0;
}
