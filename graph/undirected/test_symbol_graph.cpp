#include "symbol_graph.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{

	char delim;
	if(argc == 2)	
		delim = ' ';
	else
		delim = argv[2][0];

	ifstream ifs;
	ifs.open(argv[1]);
	symbol_graph sgraph(ifs, delim);	

	cout << " graph loaded in memory " << endl;
	graph &g = sgraph.g();
	//cout << g << endl;
	
	cin.clear();
	string line;	
	while(getline(cin, line))
	{
		vector<int> adj = g.adj(sgraph.index(line));
		for(int i = 0 ; i < adj.size(); ++i)
		{
			cout << "\t" << sgraph.name(adj[i]) << endl;;
		}
	}
	return 0;
}
