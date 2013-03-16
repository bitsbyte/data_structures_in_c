#include "directed_cycle.h"
#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char* argv[])
{
		
	ifstream ifs;
	ifs.open(argv[1]);

	digraph g(ifs);

	cout << "graph loaded in memory" << endl;
	cout << g << endl;

	directed_cycle dc(g);
	cout << "g has cycle ? : " << dc.has_cycle() << endl;
	
	const vector<int> &cycle = dc.cycle();
	for(int i = 0 ; i < cycle.size(); ++i)
		cout << cycle[i] << " " ;
	cout << endl;		
		
	return 0;
}




