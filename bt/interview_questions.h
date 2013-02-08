#ifndef _INTERVIEW_QUESTIONS_H
#define _INTERVIEW_QUESTIONS_H value

#include <stdio.h>
#include "binary_tree_util.h"
#include <vector> 
#include <iostream>

using namespace std;

// Tree level starts from 1 at root.
void print_tree_level(tree *root, int level)
{
	if( root != NULL && level > 0 )
	{
		if( level == 1 )
			printf("%d ", root->data);
		print_tree_level(root->left, level -1);
		print_tree_level(root->right, level -1);
	}
}

// Tree level starts from 1 at root.
void print_treenr(treenr *root)
{
	if( root != NULL )
	{
		cout << " (" << root->data << "-->" << (root->next_right != NULL ? root->next_right->data : -1) << ") ";
		print_treenr(root->left);
		print_treenr(root->right);
	}
}

/*
 *  Print binary tree in level order 
 *  from top to bottom 
 *  Q: http://www.careercup.com/question?id=15259825
 *  ( to print from bottom to top change for loop )
 */
void print_level_order(tree *root)
{
	int height = max_height(root);
	int i;
	for( i = 1; i <= height; i++)
	{
		print_tree_level(root,i);
		printf("\n");
	}

}

/* Q: http://www.careercup.com/question?id=15194768
 * given a binary tree and a leaf node.
 * holding that leaf node and whole tree falls down such that it is the new root of the tree.
 * return the modified tree.
 * IDEA: reverse links from root to leaf 
*/
vector<tree*> visited_nodes;
vector<tree*> store;

static void visit(tree *node)
{
	visited_nodes.push_back(node);
}

static void unvisit(tree *node)
{
	visited_nodes.pop_back();
}

static void onfound(tree *node)
{
	store = visited_nodes;
}

tree * hold_leaf_tree_upside_down(tree *root, tree *leaf)
{
	if( root == NULL || leaf == NULL)
		return NULL;
	
	visited_nodes.clear();
	store.clear();	
	dfs(root, leaf, visit, unvisit, onfound,0);
	
	tree *curr, *prev = 0;
	int i;

	// reverse links from  root to leaf
	for(i = 0 ; i < store.size() -1 ; ++i)
	{
		curr = store[i];
		if( curr->left == store[i+1])
		{
			curr->left = prev;
		}
		else
			curr->right = prev;

		prev = curr;
	}
	store[i]->left = prev; // can also be right child 
						   // doesnt matter as it was leaf
	return store.back(); //shoud be same as leaf

} 

/* Q: http://www.careercup.com/question?id=15190793
 * Print nodes at distance K 
 */

vector<tree*> visit_stack;
vector<tree*> store_stack;

void visit1(tree *t)
{
	visit_stack.push_back(t);
}

void unvisit1(tree *t)
{
	visit_stack.pop_back();
}

void onfound1(tree *t)
{
	store_stack = visit_stack;
}

void print_nodes_at_distance_k(tree *r, tree *n, int k)
{
	if( !r || !n || k < 0 ) 
		return;
	visit_stack.clear();
	store_stack.clear();

	print_tree_level(n, k+1);

	if( r == n || k == 0)
		return;

	dfs(r, n, visit1, unvisit1, onfound1,0);

	int i , size_1 = store_stack.size() -1 ;

	for (int i = store_stack.size() -2  ; (k >= (size_1 -i)) && i >= 0; --i)
	{
		if( (size_1 - i) == k  ) 
			print_tree_level(store_stack[i], 1);
		else if( store_stack[i]->left == store_stack[i+1] )
			print_tree_level(store_stack[i]->right, k - ( size_1 - i));
		else
			print_tree_level(store_stack[i]->left, k - (size_1 -i));
	}
}

/* Q: http://www.careercup.com/question?id=15203723
Given a Binary Tree (not BST) with integer values . 
	1) Find path from root to any node with max sum. 
	2) As there can be many path's find all of them. 
	3) Print all such paths.
	Do this in O(n) : n is number of node's in tree. 
	he wanted an O(n) solution not O(n)+O(n) ie. u can't traverse tree twice .
*/

vector<tree*> stack;
vector< vector<tree*> > all_max_paths;
int max_sum = INT_MIN;
int sum = 0;

void visit2(tree *n)
{
	stack.push_back(n);
	sum += n->data;
	if( max_sum == sum )
	{
		all_max_paths.push_back(stack);
	}
	else if( max_sum < sum)
	{
		max_sum = sum;
		all_max_paths.clear();
		all_max_paths.push_back(stack);
	}
}

void unvisit2(tree *n)
{
	stack.pop_back();
}

void on_complete(tree *n)
{
	sum -= n->data;
}

void find_path_from_root_to_node_with_max_sum(tree *root)
{
	if( !root ) 
		return;
	stack.clear();
	all_max_paths.clear();

	dfs(root, 0, visit2, unvisit2, 0, on_complete);

	cout  << "max paths found : max_sum : " << max_sum << "\n";
	int i,j;
	for ( i = 0; i < all_max_paths.size(); ++i)		
	{
		vector<tree*> &v = all_max_paths[i];
		for ( j = 0; j < v.size(); ++j)
		{
			cout << v[j]->data << "  ";
		}
		cout << endl;
	}

}

/* Q: http://www.careercup.com/question?id=15065869
A binary tree is given with left and right populated but 
the nextRight pointers in each node are not populated. 
Populate the nextRight pointer in each node.
*/

vector<treenr*> same_level_nodes;

int find_heightnr(treenr *t)
{
	if(!t)
		return 0;
	return 1 + max(find_heightnr(t->left),find_heightnr(t->right));
}

void find_nodes(treenr *r, int level)
{
	if(!r || level <= 0 ) return;
	
	if( level == 1)
		same_level_nodes.push_back(r);
	find_nodes(r->left, level -1);
	find_nodes(r->right, level -1);
}

void connect()
{
	for (int i = 0; i < same_level_nodes.size() -1 ; ++i)
	{
		same_level_nodes[i]->next_right = same_level_nodes[i+1];
	}
}

void connect_nextright(treenr *t)
{
	int height = find_heightnr(t);
	for(int i = 1; i <= height; ++i)
	{	
		same_level_nodes.clear();
		find_nodes(t,i);
		connect();
	}
}

#endif
