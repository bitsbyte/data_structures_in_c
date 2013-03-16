#include <iostream>
#include "digraph.h"

using namespace std;


int main(int argc, char* argv[])
{
	digraph g1(6);
	
	cout << "first graph: " << endl;
	cout << g1 << endl;
	cout << "reverse of first graph" << endl;
	cout << g1.reverse() << endl;
	
	digraph g2(cin);
	cout << "second graph: " << endl;
	cout << g2 << endl;
	cout <<  "reverse of 2nd graph : " << endl;
	cout << g2.reverse() << endl;
	return  0;
}
