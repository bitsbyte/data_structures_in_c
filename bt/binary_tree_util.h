#ifndef _BINARY_TREE_UTIL_H
#define _BINARY_TREE_UTIL_H

#include "binary_tree.h"
#include "../util.h"
#include <stdlib.h> // for malloc , rand
#include <time.h>  	// for time(NULL)
#include <limits.h> // for INT_MIN
#include <math.h>  	// for log() pow()


// BST.
// intial empty tree should be passed with *root value 0.
// discard duplicate value
int insert(tree **root, int value)
{
	tree *r, *prev;

	if( !root )
		return -1;

	if( !(*root) ) 
	{
		*root = newnode(value,0,0);
		return (*root == NULL) ? -1 : 0;
	}
	else
	{
		r = *root;
		prev = 0;
		while( r != NULL )
		{
			prev = r;
			if( r->data > value )
				r = r->left;
			else if( r->data < value )
				r = r->right;
			else
				return -1; // duplicate value
		}

		if( prev->data < value ) 
			prev->right = newnode(value, 0, 0);
		else
			prev->left = newnode(value, 0, 0);
	}

}

// BST
tree * create_random_tree(int n, int min, int max)
{
	if( n > (max-min +1)  ) // no such BST is possible
		return NULL;

	tree  *t = 0;
	srand(time(NULL));
	while(n--) 
	{
		int value  =  (int)(((float)rand()/(float)RAND_MAX)*(max-min) + min);
		if(insert(&t, value) < 0 ) 
			n++; // insert failed may be due to duplicate
	}
	return t;
}

// BST
tree *search(tree *t, int value)
{
	while( t != NULL )
	{
		if( t->data > value )
			t = t->left;
		else if( t->data < value)
			t = t->right;
		else 
			return t;
	}
	return 0;
}

// BST
void delete_by_copying(tree **root, int value)
{
	if( !root || !(*root) )
		return;

	tree *current = *root;
	tree *parent = 0;
	tree *predecessor;

	while( current != NULL && current->data != value )
	{
		parent = current;
		if( current->data < value ) 
			current = current->right;
		else
			current = current->left;
	}

	if(!current) 
		return;

	if( current->left == NULL )
	{	
		if( !parent ) // root to be deleted == current
			*root = current->right;
		else if( parent->left == current )
			parent->left = current->right;
		else
			parent->right = current->right;
	}
	else if( current->right == NULL )
	{
		if( !parent ) 
			*root = current->left;
		else if( parent->left == current )
			parent->left = current->left;
		else
			parent->right = current->left;
	}
	else
	{
		// find predecessor
		parent = current;
		predecessor = current->left;
		while( predecessor->right  != NULL )
		{
			parent = predecessor;
			predecessor = predecessor->right;
		}
		current->data = predecessor->data;

		if( parent == current)
			parent->left = predecessor->left;
		else
			parent->right = predecessor->left;
		current = predecessor;

	}
	free(current);

}


/*BST:  Right rotate around P : 
       G                  G
       |                  |
       P                  C  ( can be left or right of G)
      / \       ==>      /  \
     C   Pr             Cl   P
    / \                     / \
   Cl Cr                   Cr  Pr

   G is null when rotating around tree's root node
 */
static void rotate_right(tree *G, tree **P)
{
	tree *C = (*P)->left;
	(*P)->left = C->right;
	C->right = (*P);
	if( G != NULL ) 
	{
		if( G->right == *P )
			G->right = C;
		else
			G->left = C;
	}
	(*P) = C;
}

/*BST:  Left rotate around P : 
       G                  G 
       |                  |
       P                  C
      / \       ==>      /  \
    Pl   C              P    Cr
        / \            / \
       Cl Cr          Pl  Cl

   G is null when rotating around tree's root node
 */
static void rotate_left(tree *G, tree **P)
{
	tree *C = (*P)->right;
	(*P)->right = C->left;
	C->left = (*P);
	if( G != NULL ) 
	{
		if( G->left == *P )
			G->left = C;
		else
			G->right = C;
	}
	*P = C;
}

// BT/BST:
// converts a binary tree to a linked list
// with node->right pointing to next element.
void create_backbone(tree **root)
{
	if( !root || !(*root) )
		return;

	tree *r = *root;
	while( r->left != NULL )
		rotate_right(0, &r);
	
	*root = r;
	tree *G = r;
	tree *P = r->right;
	while( P != NULL )
	{
		while( P->left != NULL )
			rotate_right(G, &P);
		G = P;
		P = P->right;
	}

}

/* BST:
 *	Run DSW algorithm to balance a tree
 */

void balance_tree(tree **root, int n)
{
	if( !root || !(*root) ) 
		return;

	tree *top, *newtop, *P, *G;
	int m, rotations;

	create_backbone(root);

	// find closest number of nodes m ( < n ) 
	// in a completely balanced binary tree
	// 2^(floor(log_base2(n+1)))
	m =  pow(2,(int)(log(n+1)/log(2))) - 1; 
	rotations = n - m;
	top = *root;
	G = 0;

	if( rotations )
		newtop = top->right;
	else
		newtop = top;

	while( rotations-- )
	{
		rotate_left(G, &top);
		G = top;
		top = top->right;
	}
	// each iteration halves tree height
	while( m > 1 )
	{
		m  = m/2;
		rotations = m;
		top = newtop;
		G = 0;
		// store newtop for next iteration
		newtop = newtop->right;
		while( rotations-- )
		{
			rotate_left(G, &top);
			G = top;
			top = top->right;
		}
	}

	// update root of tree
	if( n > 1 )
		*root = newtop;
}

/* BST */
tree * find_predecessor(tree *root, int value)
{
	if( !root )
		return NULL;

	tree *predecessor = 0;
	tree *current = root;

	while( current != NULL ) 
	{
		if( current->data < value )
		{ //  right turn can be precessor if value_node's left is null
			predecessor = current;
			current = current->right;
		}
		else if( current->data > value ) 
		{
			current = current->left;
		}
		else 
		{
			if( current->left != NULL )
			{
				predecessor = current->left;
			}
			break;
		}
	}

	return predecessor;
}


/* BST */
tree * find_successor(tree *root, int value)
{
	if( !root )
		return NULL;

	tree *successor = 0;
	tree *current = root;

	while( current != NULL ) 
	{
		if( current->data < value )
		{ 
			current = current->right;
		}
		else if( current->data > value ) 
		{
			//  left turn can be successor if value_node's right is null
			successor = current;
			current = current->left;
		}
		else 
		{
			if( current->right != NULL )
			{
				successor = current->right;
			}
			break;
		}
	}

	return successor;
}


/* BT / BST */
tree* find_lca(tree *root, tree* p, tree* q)
{
	if(!root)
		return NULL;

	if( root == p || root == q )
		return root;
	else
	{
		tree *l = find_lca(root->left, p, q);
		tree *r = find_lca(root->right, p, q);
		if( l && r )
			return root;
		else if( l )
			return l;
		else if( r )
			return r;
		else 
			return NULL;
	}
}

/* BST : O(log(n)) */ 
tree *find_lca_in_bst(tree *root, int small, int big)
{
	if( !root )
		return NULL;

	if( root->data <= big && root->data >= small )
		return root;
	else if( root->data > big )
		return find_lca_in_bst(root->left, small, big);
	else if( root->data < small )
		return find_lca_in_bst(root->right, small, big);
}

//BST : O(n)
tree* find_kth_largest(tree *root, int *k)
{
	// do reverse inorder and keep decrementing k 
	// when k reaches 1 , we are at kth largest. 
	if(!root) 
		return NULL;

	tree *kth = NULL;

	kth = find_kth_largest(root->right, k);
	if( kth != NULL ) return kth;
	if( *k == 1)
		return root;
	*k = *k - 1;
	kth = find_kth_largest(root->left, k);
	if( kth != NULL ) return kth;

	return NULL;
}

//BT/BST
int max_height(tree *root)
{
	if( !root )
		return 0;
	return max(max_height(root->left)+1, max_height(root->right)+1);
}

//BT/BST
void dfs(tree *root, tree *n, void (*visit)(tree *n), void (*unvisit)(tree *n), void (*onfound)(tree *n), void (*on_complete)(tree *t))
{
	if(!root)
		return;
	if(visit != NULL)
		visit(root);

	if( n!= NULL && root == n)
		if(onfound != NULL)
			onfound(root);

	dfs(root->left, n, visit, unvisit, onfound, on_complete);

	dfs(root->right, n, visit, unvisit, onfound, on_complete);

	if( unvisit != NULL )
		unvisit(root);
	if( on_complete != NULL)
		on_complete(root);
}

/*
 * BST/BT: idea: a tree is balanced if
 * 1)  its left subtre & its right are balanced
 * 2) diff of max_left_height & max_right_height is at max 1
 */
int is_balanced(tree *root, int *height)
{
	// empty tree is balanced
	if(!root) 
	{
		*height = 0;
		return 1;
	}

	int left_height = 0;
	int right_height = 0;
	int is_left_balanced = is_balanced(root->left, &left_height);
	int is_right_balanced = is_balanced(root->right, &right_height);

	*height = max(left_height,right_height) + 1;

	if( is_left_balanced && is_right_balanced && abs(left_height - right_height) <= 1)
		return 1;
	return 0;
}

#endif

