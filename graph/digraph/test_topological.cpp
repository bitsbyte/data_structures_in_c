#include "topological.h"
#include "symbol_digraph.h"
#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream ifs;
	ifs.open(argv[1]);
	
	symbol_digraph sdg(ifs,argv[2][0]);
	digraph g = sdg.g();
	topological topo(g);
	
	cout << "is_dag : " << topo.is_dag() << endl;
	if( topo.is_dag())
	{
		cout << "topological sort : \n"; 
		stack<int> order = topo.topological_order();
		while(!order.empty())
		{
			cout << sdg.name(order.top()) << endl ;
			order.pop();
		}
		cout << endl;
	}

	return 0;	
}

