#include <stdio.h>
#include "binary_tree_util.h"
#include "binary_tree_print.h"
#include "../ar/array_util.h" // for shuffle

void die()
{
	printf("usage: test_bt number_of_nodes min max\n");
	exit(1);
}

void test(char *msg, int testnum)
{
	printf("=============================================\n");
	printf("TEST %d : %s \n", testnum, msg);
	printf("=============================================\n");
}

// create random tree and print
test1(int n, int min, int max)
{
	test("create random tree and print",1);
	tree *t = 0;
	t  = create_random_tree(n, min, max);
	print_ascii_tree(t);
	free_tree(t);
}

// search from min to max
void test2(int n, int min, int max)
{
	test("search elements between min & max",2);
	int i;
	tree *result;
	tree *t = create_random_tree(n, min, max);
	print_ascii_tree(t);

	for( i = min ; i < max; ++i)
	{
		result = search(t,i);
		if( result != NULL )
			printf("%d found \n", i);
	}
	free_tree(t);
}

// delete within min and max
void test3(int n, int min, int max)
{
	test("delete elements between min & max",3);
	int i, size ;
	tree *t = create_random_tree(n, min, max);
	size = max - min;
	int *a = (int *) malloc(size*sizeof(int));

	for( i = 0 ; i < size; ++i)
		a[i] = i;
	shuffle(a, size);
	for(i = 0 ; i <  size; ++i)
	{
		printf("Delete : %d\n", a[i]);
		delete_by_copying(&t, a[i]);
		print_ascii_tree(t);
	}
	free(a);
	free_tree(t);
}

// test binary tree to linked list conversion
void test4(int n, int min, int max)
{
	test("convert binary tree to linked list",4);

	tree *t = create_random_tree(n,min,max);
	print_ascii_tree(t);
	printf("Binary Tree to Linked List: \n");
	create_backbone(&t);
	print_ascii_tree(t);
	free_tree(t);
}

// test balancing of a binary tree
void test5(int n, int min, int max)
{
	test("balance binary tree ", 5);
	tree *t = create_random_tree(n, min, max);
	printf("Binary Tree: \n");
	print_ascii_tree(t);
	printf("Balanced Tree: \n");
	balance_tree(&t, n);
	print_ascii_tree(t);
}

int main(int argc, char* argv[])
{
	int n, min, max;
	tree *t;

	if( argc < 4 )
		die();
	
	n = atoi(argv[1]);
	min = atoi(argv[2]);
	max = atoi(argv[3]);

	test1(n, min, max);
	test2(n, min, max);
	test3(n, min, max);
	test4(n, min, max);
	test5(n, min, max);
	printf("tests complete\n");
	//free_tree(t);  // test3() deletes whole tree
}
