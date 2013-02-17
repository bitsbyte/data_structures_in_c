#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <vector>

void test(char *msg, int testnum)
{ 
  printf("=============================================\n");
  printf("TEST %d : %s \n", testnum, msg);
  printf("=============================================\n");
}


void test_maxheap_creation(int size, int min, int max)
{
	test("random heap creation",1);
	heap *h = create_random_maxheap(size, min, max);
	print_maxheap(h);
	delete h;
} 

void test_maxheap_enqueue(int size, int min, int max)
{
	test("maxheap enqueue",2);
	heap h;	
	srand(time(NULL));
	for( int i = 0; i < size; ++i)
	{
		int value = (((float)rand()/(float)RAND_MAX)*(max-min) + min);
		printf("enqueuing %d\n",value);
		enqueue_maxheap(&h, value);
		print_maxheap(&h);
	}	
} 

void test_maxheap_dequeue(int size, int min, int max)
{
	test("maxheap dequeue",3);
	heap *h = create_random_maxheap(size, min, max);
	assert(h!=NULL);
	print_maxheap(h);
	int sz = h->data.size();
	while(sz--)
	{
		printf("%d ", dequeue_maxheap(h));
	}
	printf("\n");
	delete h;
}  

void die()
{
	printf("usage: test_heap size min max\n");
	exit(1);
} 


int main(int argc, char* argv[])
{
	if(argc < 4 )
		die();
	
	int size = atoi(argv[1]);
	int min = atoi(argv[2]);
	int max = atoi(argv[3]);	
	
	//printf("size: %d, min: %d, max: %d\n",size,min,max);
	test_maxheap_creation(size, min, max);
	test_maxheap_enqueue(size, min, max);
	test_maxheap_dequeue(size, min, max);	
  return 0;
}
