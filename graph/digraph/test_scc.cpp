#include "scc.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

int  main(int argc, char* argv[])
{
	ifstream ifs;
	ifs.open(argv[1]);
	
	digraph g(ifs);
	scc _scc(g);
	unordered_map<int, vector<int> > components;

	for(int s = 0 ; s < g.v(); ++s)
	{
		components[_scc.id(s)].push_back(s);
	}	

	cout << "components : " << endl;
	
	for(auto it = components.begin(); it != components.end(); ++it)
	{
		vector<int> &cc = it->second;
		cout <<  it->first << " : " ;
		for(int i = 0 ; i < cc.size(); ++i)
		{	
			cout << cc[i] << " ";
		}
		cout << endl;
	}	
			
	return 0;	
}
