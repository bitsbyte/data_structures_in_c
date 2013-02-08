#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <stdlib.h> // for malloc , rand

typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
} tree;

typedef struct treenr 
{
	int data;
	struct treenr *left;
	struct treenr *right;
	struct treenr *next_right; /* points to next sibling to the right */
} treenr;

typedef struct treelr
{
	int data;
	struct treelr *left;
	struct treelr *right;
	int le; /* number of elements in left subtree */
	int re; /* number of elements in right subtree */
} treelr;


tree * newnode(int data, tree *left, tree *right)
{
	tree *n = (tree*) malloc(sizeof(tree));
	n->data = data;
	n->left = left;
	n->right = right;
	return n;
}

treenr * newnodenr(int data, treenr *left, treenr *right, treenr *nr)
{
	treenr *n = (treenr*) malloc(sizeof(treenr));
	n->data = data;
	n->left = left;
	n->right = right;
	n->next_right = nr;
	return n;
}

treelr * newnodelr(int data, treelr *left, treelr *right)
{
	treelr *n = (treelr*) malloc(sizeof(treelr));
	n->data = data;
	n->left = left;
	n->right = right;
	n->le = -1;
	n->re = -1;
	return n;
}

// BT/BST
void free_tree(tree  *t)
{
	if( t != NULL )
	{
		free_tree(t->left);
		free_tree(t->right);
		free(t);
	}
}

void free_treenr(treenr  *t)
{
	if( t != NULL )
	{
		free_treenr(t->left);
		free_treenr(t->right);
		free(t);
	}
}

void free_treelr(treelr  *t)
{
	if( t != NULL )
	{
		free_treelr(t->left);
		free_treelr(t->right);
		free(t);
	}
}

#endif
