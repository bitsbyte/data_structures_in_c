#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include<stdlib.h>

typedef struct ll {
	int data;
	struct ll *next;
} ll;

ll* node(int data, ll* next)
{
	ll* newnode = (ll*) malloc(sizeof(ll));
	newnode->data = data;
  newnode->next = next;
	return newnode;
}

#endif
