#include "serialize_deserialize_bt.h"
#include "binary_tree_util.h"
#include "binary_tree_print.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


void test_sd(tree *t, void (*ser)(tree *t, vector<string> &nodes), 
										  tree* (*des)(vector<string> nodes, int &cur_idx),
											int is_postorder, string msg)
{
	cout << "-----------------------------------------------" << endl;
	cout << msg << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "serializing tree ..." << endl;
	vector<string> nodes;
	ser(t,nodes);

	for(int i = 0 ; i < nodes.size(); ++i)
		cout << nodes[i] << "\t";
	cout << endl;

	cout << "deserializing tree ..." << endl;
	int index = is_postorder ? (nodes.size() -1) : 0;
	tree *dt = des(nodes,index);

	print_ascii_tree(dt);
	free_tree(dt);	
}


int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		cout << "usage: test_serialize_deserialize_bt number_of_nodes_in_bt" << endl;
		return 1;
	}

	int size = atoi(argv[1]);
	tree *t = create_random_tree(size,0,20);
	print_ascii_tree(t);
	
	test_sd(t, serialize_preorder, deserialize_preorder, 0, "PREORDER");	
	
/* INORDER IS NOT UNIQUE: hence generation of tree again is not possible:
	inorder output is of the form : 
		$ d1 $ d2 $ d3 $ d4 $ 
	above  inorder squence can belong to many trees : 
				d2                  d3
			/   \                /  \
		 d1    d4   OR        d2   d4
					/              /
				 d3             d1
*/
	
	test_sd(t, serialize_postorder, deserialize_postorder, 1, "POSTORDER");

	free_tree(t);
		
	return 0;
}
