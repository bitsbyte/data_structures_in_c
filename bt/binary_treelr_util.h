#ifndef _BINARY_TREELR_UTIL_H
#define _BINARY_TREELR_UTIL_H 

#include "binary_tree.h"
#include "../util.h"
#include <stdlib.h> // for malloc , rand
#include <time.h>  	// for time(NULL)
#include <limits.h> // for INT_MIN
#include <math.h>  	// for log() pow()
// BST.
// intial empty treelr should be passed with *root value 0.
// discard duplicate value
int insertlr(treelr **root, int value)
{
	treelr *r, *prev;

	if( !root )
		return -1;

	if( !(*root) ) 
	{
		*root = newnodelr(value,0,0);
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
			prev->right = newnodelr(value, 0, 0);
		else
			prev->left = newnodelr(value, 0, 0);
	}

}

// BST
treelr * create_random_treelr(int n, int min, int max)
{
	if( n > (max-min +1)  ) // no such BST is possible
		return NULL;

	treelr  *t = 0;
	srand(time(NULL));
	while(n--) 
	{
		int value  =  (int)(((float)rand()/(float)RAND_MAX)*(max-min) + min);
		if(insertlr(&t, value) < 0 ) 
			n++; // insert failed may be due to duplicate
	}
	return t;
}

// BST
treelr *searchlr(treelr *t, int value)
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
void delete_by_copyinglr(treelr **root, int value)
{
	if( !root || !(*root) )
		return;

	treelr *current = *root;
	treelr *parent = 0;
	treelr *predecessor;

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
static void rotate_rightlr(treelr *G, treelr **P)
{
	treelr *C = (*P)->left;
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
static void rotate_leftlr(treelr *G, treelr **P)
{
	treelr *C = (*P)->right;
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
// converts a binary treelr to a linked list
// with node->right pointing to next element.
void create_backbonelr(treelr **root)
{
	if( !root || !(*root) )
		return;

	treelr *r = *root;
	while( r->left != NULL )
		rotate_rightlr(0, &r);
	
	*root = r;
	treelr *G = r;
	treelr *P = r->right;
	while( P != NULL )
	{
		while( P->left != NULL )
			rotate_rightlr(G, &P);
		G = P;
		P = P->right;
	}

}

/* BST:
 *	Run DSW algorithm to balance a tree
 */

void balance_treelr(treelr **root, int n)
{
	if( !root || !(*root) ) 
		return;

	treelr *top, *newtop, *P, *G;
	int m, rotations;

	create_backbonelr(root);

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
		rotate_leftlr(G, &top);
		G = top;
		top = top->right;
	}
	// each iteration halves treelr height
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
			rotate_leftlr(G, &top);
			G = top;
			top = top->right;
		}
	}

	// update root of tree
	if( n > 1 )
		*root = newtop;
}

/* BST */
treelr * find_predecessorlr(treelr *root, int value)
{
	if( !root )
		return NULL;

	treelr *predecessor = 0;
	treelr *current = root;

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
treelr * find_successorlr(treelr *root, int value)
{
	if( !root )
		return NULL;

	treelr *successor = 0;
	treelr *current = root;

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

//BST : O(n)
treelr* find_kth_largestlr(treelr *root, int *k)
{
	// do reverse inorder and keep decrementing k 
	// when k reaches 1 , we are at kth largest. 
	if(!root) 
		return NULL;

	treelr *kth = NULL;

	kth = find_kth_largestlr(root->right, k);
	if( kth != NULL ) return kth;
	if( *k == 1)
		return root;
	*k = *k - 1;
	kth = find_kth_largestlr(root->left, k);
	if( kth != NULL ) return kth;

	return NULL;
}

// BST: O(log(n)) : if tree is  balanced

treelr* find_kth_largest_logn(treelr *root, int k)
{
	if( !root ) 
		return NULL;

	if( root->re == k )
		return root;
	else if( root->re > k )
		return find_kth_largest_logn(root->right, k);
	else
		return find_kth_largest_logn(root->left, k - root->re - 1);
}

void populate_lr(treelr *t)
{
	if(!t) return;

	populate_lr(t->left);
	populate_lr(t->right);

	if( !t->left && !t->right )
	{
		t->le = t->re = 0;
	}
	else if( !t->left && t->right != NULL )
	{
		t->le = 0;
		t->re = t->right->re + t->right->le + 1;
	}
	else if( t->left != NULL && !t->right  )
	{
		t->re = 0;
		t->le = t->left->re + t->left->le + 1;
	}
	else
	{
		t->re = t->right->re + t->right->le + 1;
	 	t->le = t->left->re + t->left->le + 1;	
	}
}

//BT/BST
int max_heightlr(treelr *root)
{
	if( !root )
		return 0;
	return max(max_heightlr(root->left)+1, max_heightlr(root->right)+1);
}

//BT/BST
void dfslr(treelr *root, treelr *n, void (*visit)(treelr *n), void (*unvisit)(treelr *n), void (*onfound)(treelr *n), void (*on_complete)(treelr *t))
{
	if(!root)
		return;
	if(visit != NULL)
		visit(root);

	if( n!= NULL && root == n)
		if(onfound != NULL)
			onfound(root);

	dfslr(root->left, n, visit, unvisit, onfound, on_complete);

	dfslr(root->right, n, visit, unvisit, onfound, on_complete);

	if( unvisit != NULL )
		unvisit(root);
	if( on_complete != NULL)
		on_complete(root);
}


#endif