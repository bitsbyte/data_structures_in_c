#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "interview_questions.h"
#include "binary_tree_util.h"
#include "binary_treelr_util.h"
#include "binary_tree_print.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"

void test(char *msg, int testnum)
{
	printf("=============================================\n");
	printf("TEST %d : %s \n", testnum, msg);
	printf("=============================================\n");
}

void test_level_order()
{
  test("print tree in level order",1);
  tree *t = create_random_tree(10,20,100);
  print_ascii_tree(t);
  printf("Level Order: \n");
  print_level_order(t);	
  free_tree(t);
}

void test_leaf_becomes_root()
{
	test("hold leaf so that rest of the tree falls down and leaf beomes new root",2);
	tree *leaf;
	tree *r = newnode(1,
	/* left subtree */	newnode(2, newnode(4,0,0), newnode(5,0,0)),
    /* right subtree*/	newnode(3, newnode(12,0,0), (leaf =newnode(6,0,0))  ));
	print_ascii_tree(r);
	printf("after hanging upside down about : %d\n", leaf->data);

	tree *newroot =	hold_leaf_tree_upside_down(r, leaf);
	print_ascii_tree(newroot);	
	free_tree(newroot);
}

void test_print_nodes_at_distance_k()
{
	test("test print all nodes at distance K ",3);
	tree *n;
	 // a node is followed by its left and right child in new line ( at same indentation)
	tree *r = newnode(1, 
	/* left subtree */	newnode(11,
						           newnode(2, 
						           			(n = newnode(4, 
						           							newnode(123, 
						           										newnode(44,0,0), 
						           										newnode(89,0,0))
						           							,newnode(33, 
						           										newnode(76,0,0) , 
						           										newnode(99,0,0)   ))),
								 			newnode(5,
								 						newnode(13,0,0),
								 						newnode(14,0,0))) , 
						           newnode(45,newnode(46,0,0),newnode(48,0,0))),
    /* right subtree*/	newnode(3, 
    								newnode(12,0,0), 
    								newnode(6,0, 
    											newnode(54,0,
    											newnode(55,0,0)))
    								  ));
	print_ascii_tree(r);
	int k = 0 ;

	for( k = 0 ; k < 10 ; ++k) 
	{
		printf("nodes at distance K : %d\n", k);
		print_nodes_at_distance_k(r, n, k);
		printf("\n");
	}
	free_tree(r);
}

void test_print_all_paths_from_root_with_max_sum()
{
	test("all paths from root to node with max sum: ",4);
	tree *l = create_random_tree(5,-100,100);
	tree *t = newnode(999,l,l);
	print_ascii_tree(t);
	find_path_from_root_to_node_with_max_sum(t);
	free(t);
	free_tree(l);
}

void test_connect_next_right()
{
	test("connect next right : ",5);
	
	treenr *tnr = 	 newnodenr(1,
	/* left subtree */	newnodenr(2, newnodenr(4,newnodenr(7,0,newnodenr(11,0,0,0),0),0,0), newnodenr(5,0,0,0),0),
    /* right subtree*/	newnodenr(3, newnodenr(12,newnodenr(8,0,0,0),newnodenr(9,newnodenr(13,0,newnodenr(17,0,0,0),0),0,0),0), newnodenr(6,0,newnodenr(10,0,
		newnodenr(18,0,newnodenr(19,0,0,0),0),0),0),0  ), 0);
	connect_nextright(tnr);
	print_treenr(tnr);
	cout << "\n";
	free_treenr(tnr);
}

// 1st based k
void test_find_kth_largest()
{
	test("find kth largest ",6);
	tree *t = create_random_tree(10,-100,100);
	print_ascii_tree(t);
	for (int i = 1; i <= 15; ++i)
	{
		int k = i;
		tree *kth = find_kth_largest(t,&k);
		cout <<  "find " << i << " largest: " << (kth == NULL ? -1 : kth->data) << endl;
	}
	
	free_tree(t);
}

// 0th based k 
void test_find_kth_largest_logn()
{
	/* keep above and this function consecutive so that tree generated is same 
		and we dont have to copy print function for treelr */
	test("find kth largest ( log(n) on balanced tree ) ",7);
	treelr *t = create_random_treelr(10,-100,100);
	//print_ascii_tree(t);
	populate_lr(t);
	for (int i = 0; i <= 15; ++i)
	{
		int k = i;
		treelr *kth = find_kth_largest_logn(t,k);
		cout <<  "find " << i << " largest: " << (kth == NULL ? -1 : kth->data) << endl;
	}
	
	free_treelr(t);
}

int main(int argc, char* argv[])
{
  test_level_order();
  test_leaf_becomes_root();
  test_print_nodes_at_distance_k();
  test_print_all_paths_from_root_with_max_sum();
  test_connect_next_right();
  test_find_kth_largest();
  test_find_kth_largest_logn();
  return 0;
}
 
