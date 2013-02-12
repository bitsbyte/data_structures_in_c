#ifndef _INTERVIEW_QUESTIONS_H
#define _INTERVIEW_QUESTIONS_H value

#include <stdio.h>
#include "binary_tree_util.h"
#include "../ar/array_util.h"
#include <vector> 
#include <queue>
#include <stack>
#include <iostream>
#include <unordered_map>


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

vector<tree*> stack_;
vector< vector<tree*> > all_max_paths;
int max_sum = INT_MIN;
int sum = 0;

void visit2(tree *n)
{
	stack_.push_back(n);
	sum += n->data;
	if( max_sum == sum )
	{
		all_max_paths.push_back(stack_);
	}
	else if( max_sum < sum)
	{
		max_sum = sum;
		all_max_paths.clear();
		all_max_paths.push_back(stack_);
	}
}

void unvisit2(tree *n)
{
	stack_.pop_back();
}

void on_complete(tree *n)
{
	sum -= n->data;
}

void find_path_from_root_to_node_with_max_sum(tree *root)
{
	if( !root ) 
		return;
	stack_.clear();
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

/* Q: http://www.careercup.com/question?id=15028720
 * Given a binary tree, such that each node contains a number. 
 * Find the maximum possible sum in going from one leaf node to another.

  node->re is unused
  node-> le contains max sum from that node to its leaves
*/

int find_max_sum_from_leaf_to_leaf(tree *root, int *max )
{
	if( root == NULL )
		return 0;
	
	int maxl = find_max_sum_from_leaf_to_leaf(root->left, max);
	int maxr = find_max_sum_from_leaf_to_leaf(root->right, max);

	int max_at_current_node = maxl + maxr + root->data;

	if( *max < max_at_current_node )
		*max = max_at_current_node;

	return ( (maxl + root->data) > (maxr + root->data)  ? (maxl+root->data):(maxr+root->data) );
}


/* Q:http://www.careercup.com/question?id=15031741
 * Generate Ancestor Matrix , 
 * A[i][j] = 1, if i is ancestor of j ( not only immediate one).
 * i & j are zero based.
*/
vector<tree*> visit_stack_am;
int N;
static int node_index = 0;

// OUTPUT are below two variables: 
unordered_map<tree*,int> _index;
int **A  = 0;

void populate_am()
{
	for(int i = 0 ; i < visit_stack_am.size() -1; ++i )
	{
		for(int j = i+1; j < visit_stack_am.size() ; ++j )
		{
			A[ (int)(_index[ visit_stack_am[i]]) ] [ (int)(_index[visit_stack_am[j]]) ] = 1;
		}
	}
}

void visit3(tree *t)
{
	_index[t] = node_index++;
	visit_stack_am.push_back(t);
	// if leaf node populate AM
	if( t->left == NULL && t->right == NULL ) 
	{
		populate_am();
	}
}

void unvisit3(tree *t)
{
	visit_stack_am.pop_back();
}

void generate_ancestor_matrix(tree* t, int n)
{
	N = n;
	A = alloc_2d_array(n,n);
	if( !A)
		cout << "2d array allocation failed !\n";
	dfs(t, 0, visit3, unvisit3, 0, 0);
}


/* Q: http://www.careercup.com/question?id=12333722
 * Given a binary tree where each node contains an integer value and a value k,
 * print all paths which sum upto this value k
 */
vector<tree*> visit_stack1;
vector<int> cumulative_sum;
int given_sum;

void print_nodes_with_given_sum(int begin)
{
	int i;
	for( i = begin; i < visit_stack1.size(); ++i )
	{
		cout << visit_stack1[i]->data << " " ;
	}
	cout << endl;
}

void visit4(tree *t)
{
	visit_stack1.push_back(t);
	if( cumulative_sum.size() == 0 )
		cumulative_sum.push_back(t->data);
	else
	{
		int previous_sum = cumulative_sum.back();
		cumulative_sum.push_back(previous_sum + t->data);
	}

	if( cumulative_sum.back() == given_sum )
	{
		print_nodes_with_given_sum(0);
		if( cumulative_sum.front() == 0)
			print_nodes_with_given_sum(1);
	}
	else
	{
		//binary search : 
		int search = cumulative_sum.back() - given_sum;
		vector<int>::iterator it;
		it  = lower_bound(cumulative_sum.begin(),cumulative_sum.end(), search);
		if( it != cumulative_sum.end() && *it == search)
		{
			print_nodes_with_given_sum(it - cumulative_sum.begin() + 1);
		}
	}
	
}

void on_complete1(tree *t)
{
	visit_stack1.pop_back();
	cumulative_sum.pop_back();
}

// O(n log(h)) ==> O(n log( log(n)) )
 void print_all_paths_with_sum_k(tree *root, int k)
 {
 	given_sum = k;
 	cumulative_sum.clear();
 	visit_stack1.clear();
 	dfs(root,0,visit4,0,0,on_complete1);
 }


/* Q: http://www.careercup.com/question?id=12318666
Flatten a binary tree in the its inorder traversal form. Example if there is a tree like
01
0203
04050607

Flatten it to 04->02->05->01->06->03->07
Right of 4 should be pointing to 02 and so on.
The order is inorder traversal order
I was asked to use Recursion
*/
tree *previous = 0;
tree *head;
void convert_bt_to_dll(tree *root)
{
	if( !root ) 
		return;

	convert_bt_to_dll(root->left);

	if(!previous)
	{
		head = root;
		root->left = NULL;
		previous = root;
	}
	else
	{
		root->left = previous;
		previous->right = root;
		previous = root;
	}

	convert_bt_to_dll(root->right);
}

/*
	print bt in zig-zag level order
*/
unsigned int alternate;
void print_zig_zag_bt(tree *root)
{
	if(!root)
		return;
	alternate = ~0 ;
	queue<tree*> current_level;
	stack<tree*> next_level;

	current_level.push(root);

	while(!current_level.empty())
	{
		tree *current_node = current_level.front();
		current_level.pop();
		cout << current_node->data << " ";

		if( alternate ) // insert children left to right
		{
			if( current_node->left )
				next_level.push(current_node->left);
			if( current_node->right )
				next_level.push(current_node->right);
		}
		else // insert children right to left
		{
			if( current_node->right )
				next_level.push(current_node->right);
			if( current_node->left )
				next_level.push(current_node->left);
		}

		if( current_level.empty() )
		{
			while(!next_level.empty()) 
			{
				current_level.push(next_level.top());
				next_level.pop();
			}
			alternate = ~alternate;
			cout << "\n";
		}

	}

}

/* Q: http://www.careercup.com/question?id=11231922
	print vertical sums
*/
unordered_map<int,int> vertical_sum;
int number_of_nodes;
void find_vertical_sums(tree *root, int width) 
{
	if( !root )
		return;

	vertical_sum[width + number_of_nodes] += root->data; // index will always be positive
	find_vertical_sums(root->left, width - 1);
	find_vertical_sums(root->right, width +1);
}

/* Q: http://www.careercup.com/question?id=11983859
Given the head of a Binary Search tree, trim the tree, 
so that all elements in the new tree returned are between the inputs A and B
*/

tree *newroot; // set it to original root before calling function below

static void trim_bst_recurse(tree *root, tree *parent, int A, int B)
{
	if(!root)
		return;

	tree *nextnode;

	if( root->data < A )
	{
		nextnode = root->right;
		root->right = NULL;
		free_tree(root);
		if(parent)
			parent->left = nextnode;
		else
			newroot = nextnode;
		trim_bst_recurse(nextnode, parent, A, B);
	}
	else if(  root->data > B )
	{
		nextnode = root->left;
		root->left = NULL;
		free_tree(root);
		if(parent)
			parent->right = nextnode;
		else
			newroot = nextnode;
		trim_bst_recurse(nextnode, parent, A, B);
	}
	else
	{
		trim_bst_recurse(root->left, root, A, B);
		trim_bst_recurse(root->right, root, A, B);
	}
}

tree *trim_bst(tree *root, int A, int B)
{
	newroot = root;
	trim_bst_recurse(root, 0, A, B);
	return newroot;
}















#endif
