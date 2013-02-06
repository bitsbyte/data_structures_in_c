#ifndef _LINKED_LIST_UTIL_H
#define _LINKED_LIST_UTIL_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "linked_list.h"

ll* random_list(int size)
{
	int i = 0;
	ll *list = 0;
	ll *node;
	srand(time(NULL));
	for(; i < size ; ++i ) {
		node = (ll*) malloc(sizeof(ll));
		node->data = rand() % 100;
		node->next = list;
		list = node;
	}	
	return list;
}

void print_list(ll *list)
{
	while(list) {
		printf(" %d --> ", list->data);
		list = list->next; 
	}
	printf("\n");
}

void reverse_list(ll **list)
{	
	if(!list && !*list) 
		return;
		
	ll *current = *list;
	ll *next = current->next;
	ll *newlist = 0;
	while(1) {
		current->next = newlist;
		newlist = current;	
		if(!next) break;
		current = next;
		next = next->next;
	}
 	*list = newlist;	
}

 /* Given a linked list : 
	* 1) reverse list for k elements
	* 2) then traverse list for m elements
	* 3) repeat
	*/
void kreverse_mtraverse(ll **list, int k, int m)
{
	if( k <=1 || m < 0 ||  !list ||  !(*list) )
		return;
	ll *current = *list;
	ll *begin = current;
	ll *next = current->next;
	int kcount = 0;
	int mcount = 1;
	ll *newlist = 0;
	ll *begining_of_traversed_list = 0;

	// reverse k elements
	while(1) {
		current->next = newlist;
		newlist = current;
		kcount++;
		if( !next || kcount == k ) break;
		current = next;
		next = next->next;
	}

	begining_of_traversed_list = next;	
	// traverse m elements
	while( mcount < m && next != NULL)
	{
		next = next->next;
		mcount++;
	}
	
	if( m == 0 && next != NULL )
		kreverse_mtraverse(&next, k, m);
	else if( next != NULL && next->next != NULL)
		kreverse_mtraverse(&next->next, k, m);

	// update original list
	*list = newlist;	
	// point end of reversed list to begining of traversed list
	begin->next = begining_of_traversed_list;	
}

 /* Given a LL , whose two parts ( first half & second half) 
	* are sorted . Merge these two sorted half into one 
	* without using extra space
	*/
void merge_two_sorted_half_into_one(ll **list)
{
	if( !list || !(*list) ) 
		return;
	
	ll *current = *list;
	ll *previous = 0;
	ll *first = *list ;
	ll *second = 0;

	while( current->next != NULL ) {
		previous = current;
		if( current->data > current->next->data) {
			second = current->next;
			break;
		}
		current = current->next;
	}
	
	if(!second) // list is already sorted , return
		return;
	previous->next = 0; // separate two lists

	// initialize new sorted list with one smallest element
	ll* newlist = first->data < second->data ? first : second;
	if( newlist == first ) 
		first = first->next;
	else
		second = second->next;

	*list = newlist;

	// merge remaining two lists
	while( first != NULL && second != NULL )
	{
		if( first->data < second->data) {	
			newlist->next = first;
			newlist = newlist->next;
			first = first->next;
		} else {
			newlist->next = second;
			newlist = newlist->next;
			second = second->next;
		}
	}
	
	// first list empty , add elements from second list
	if(!first) {
		while( second != NULL ) {
			newlist->next = second;
			newlist = newlist->next;
			second = second->next;
		}
	}

	// second list empty , add elements from first list
	if(!second) {
		while( first != NULL) {
			newlist->next = first;
			newlist = newlist->next;
			first = first->next;
		}
	}

	
}

 /* Given two LLs , find intersection in O(n) time and O(1) space.
	*/
ll* find_intersection(ll *f, ll *s)
{	
	if (!f || !s) 
		return NULL;
	ll *first = f;
	ll *second = s;
	int diff = 0;
	
	while (first) {
		++diff;
		first = first->next;
	}

	while (second) {
		--diff;
		second = second->next;
	}

	first = f;
	second = s;
		
	if( diff > 0 ) {
		while(diff--)
			first = first->next;
	}	else {
		while(diff++)
			second = second->next;
	}

	while( first != NULL ) {
		if( first == second ) 
			return first;
		first = first->next;
		second = second->next;
	}
	
	return NULL;
}

#endif
