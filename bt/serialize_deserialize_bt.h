#include "binary_tree.h"

#include <string>
#include <vector>

void serialize(tree *t, std::vector<std::string> &nodes)
{
	if( t == NULL)
	{
		nodes.push_back("$");
		return;
	}

	nodes.push_back(std::to_string(t->data));
	serialize(t->left, nodes);
	serialize(t->right, nodes);
}


tree* deserialize(std::vector<std::string> nodes, int &current_index)
{
	if( current_index < nodes.size())
	{
		if(nodes[current_index].compare("$") == 0)	
		{
			++current_index;
			return NULL;
		}	
	
		tree *t = newnode(std::stoi(nodes[current_index]),NULL,NULL);
		++current_index;
		t->left = deserialize(nodes, current_index);
		t->right = deserialize(nodes, current_index);
		return t;
	}
	
	return NULL;
}
