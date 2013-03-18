#include "serialize_deserialize_bt.h"
#include "binary_tree_util.h"
#include "binary_tree_print.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	tree *t = create_random_tree(10,0,20);
	print_ascii_tree(t);
	
	cout << "serializing tree ..." << endl;
	vector<string> nodes;
	serialize(t,nodes);

	for(int i = 0 ; i < nodes.size(); ++i)
		cout << nodes[i] << "\t";
	cout << endl;

	cout << "deserializing tree ..." << endl;
	int index =0;
	tree *dt = deserialize(nodes,index);
	
	print_ascii_tree(dt);
	
	free_tree(t);
	free_tree(dt);	
		
	return 0;
}
