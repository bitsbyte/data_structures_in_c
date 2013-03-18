#include "binary_tree.h"

#include <string>
#include <vector>

/* INORDER IS NOT UNIQUE: hence generation of a binary tree again is not possible:
  inorder output is of the form : 
    $ d1 $ d2 $ d3 $ d4 $ 
  above  inorder sequence can belong to many trees: 
        d2                  d3
      /   \                /  \
     d1    d4   OR        d2   d4
          /              /
         d3             d1
*/



void serialize_preorder(tree *t, std::vector<std::string> &nodes)
{
	if( t == NULL)
	{
		nodes.push_back("$");
		return;
	}

	nodes.push_back(std::to_string(t->data));
	serialize_preorder(t->left, nodes);
	serialize_preorder(t->right, nodes);
}


tree* deserialize_preorder(std::vector<std::string> nodes, int &current_index)
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
		t->left = deserialize_preorder(nodes, current_index);
		t->right = deserialize_preorder(nodes, current_index);
		return t;
	}
	
	return NULL;
}


void serialize_postorder(tree *t, std::vector<std::string> &nodes)
{
	if( t == NULL)
	{
		nodes.push_back("$");
		return;
	}

	serialize_postorder(t->left, nodes);
	serialize_postorder(t->right, nodes);
	nodes.push_back(std::to_string(t->data));
}


tree* deserialize_postorder(std::vector<std::string> nodes, int &current_index_end)
{
	if( current_index_end >= 0)
	{
		if(nodes[current_index_end].compare("$") == 0)	
		{
			--current_index_end;
			return NULL;
		}	

		tree *t = newnode(std::stoi(nodes[current_index_end]), NULL, NULL);	
		--current_index_end;
		t->right = deserialize_postorder(nodes, current_index_end);
		t->left = deserialize_postorder(nodes, current_index_end);
		
		return t;
	}
	return NULL;
}
