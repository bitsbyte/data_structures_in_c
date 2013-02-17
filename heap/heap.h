#ifndef _HEAP_H
#define _HEAP_H

#include <vector>
#include <assert.h>
#include "array_util.h"
#include "binary_tree.h"
#include "binary_tree_print.h"

typedef struct heap {
	std::vector<int> data;
} heap;

//first child ( left node)
int fchild(int index)
{
	return 2*index+1;
} 
// second child (right node)
int schild(int index)
{
	return 2*index+2;
}  

int parent(int index)
{
	return (index-1)/2;
} 

/* Restore heap property for node whose
 * root is 'index'
 */
void move_down_maxheap(heap *h, int index)
{
	if(!h || h->data.size() <= index )
		return;
	
	int largest = fchild(index);
	int last = h->data.size() - 1;
	while(largest <= last)
	{
		if(largest < last && h->data[largest] < h->data[largest+1])
			++largest;
		
		if(h->data[index] < h->data[largest] )
		{
			int temp = h->data[index];
			h->data[index] = h->data[largest];
			h->data[largest] = temp;
			index = largest;
			largest = fchild(index);
		} 
		else
			break;
	}
} 

/* Restore heap property whose leaf is 'index'
 */
void move_up_maxheap(heap *h, int index)
{
	if( !h || index >= h->data.size() )
		return;
	
	int largest = parent(index);
	while(largest >= 0)
	{
		if(h->data[largest] < h->data[index] )
		{
			int temp = h->data[largest];
			h->data[largest] = h->data[index];
			h->data[index] = temp;
			index = largest;
			largest = parent(index);
		}
		else
			break; 
	}	
}  

// Priority queue implementation:
void enqueue_maxheap(heap *h, int value)
{
	if( !h ) 
		return;
	
	h->data.push_back(value);
	move_up_maxheap(h, h->data.size() -1);
}


int dequeue_maxheap(heap *h)
{
	if( !h || h->data.size() == 0)
		assert(0);

	int top = h->data[0];
	h->data[0] = h->data.back();
	h->data.pop_back();
	move_down_maxheap(h, 0);	
	return top;
}   

static tree* construct_heap_tree(std::vector<int>& data, int node_index)
{
	if( node_index >= data.size() )
		return NULL;
	
	tree *node = newnode(data[node_index],
												construct_heap_tree(data,fchild(node_index)),
												construct_heap_tree(data,schild(node_index)));
} 

void print_maxheap(heap *h)
{
	if(!h)
		return;
	//construct a binary tree out of array heap
	tree *t = construct_heap_tree(h->data, 0);
	print_ascii_tree(t);
	free_tree(t);	
} 

/* O(nlog(n)) approach: keep enqueueing new element.
	 Below is O(n)  : Floyd Algorithm
 */
void max_heapify(heap *h)
{
	if(!h || h->data.size() == 0 )	
		return ;

	int begin = h->data.size()/2 -1 ;

	while(begin >= 0)
	{
		move_down_maxheap(h, begin);
		begin--;
	}
} 


// caller should 'delete' heap after use
heap* create_random_maxheap(int size, int min, int max)
{
	if(size == 0 )
		return NULL;
	int *a = create_random_array(size, min, max);
	heap *h = new heap; 
	h->data.assign(a,a+size);
	max_heapify(h);
	free(a);
	return h;
} 

#endif
