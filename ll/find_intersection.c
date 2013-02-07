#include "linked_list_util.h"

void intersecting_list(ll **f, ll **s, int iter)
{
	switch(iter) {
		case 4:
			list4(f,s);break;
		case 3:
			list3(f,s);break;
		case 2:
			list2(f,s);break;
		case 1:
			list1(f,s);break;
		case 0:
			list0(f,s);break;
	}
}


void list4(ll** f, ll** s)
{
	*s = node(2,node(4,node(3,node(12,node(23,node(235,0))))));
 	*f = (*s)->next->next->next->next->next;	
}

void list3(ll **f, ll **s)
{
	*s = node(2,node(4,node(3,node(12,node(23,node(235,0))))));
	*f = 0;
} 

void list2(ll **f, ll **s)
{
	*f = node(2,node(4,node(3,node(12,node(23,node(235,0))))));
 	*s = 0;	
}

void list1(ll **f, ll **s)
{
	*f = node(2,node(4,node(3,node(12,node(23,node(235,0))))));
	*s = node(22,node(33, (*f)->next->next));	
}

void list0(ll **f, ll **s)
{
	*f = node(2,node(4,node(3,node(12,node(23,node(235,0))))));
	*s = node(11,node(22,node(33,node(44,0))));
}

int main()
{
	ll *f, *s;
	ll *inter;
	int iter = 5;
	while(iter--) {
	 	intersecting_list(&f,&s,iter);
	 	printf("list 1: "); 
	 	print_list(f);
	 	printf("list 2: "); 
	 	print_list(s);
	 	inter = find_intersection(f,s);
	 	if( inter != NULL)
	 		printf("intersection %d\n", inter->data);
	 	else
	 		printf("no intersection\n");
	}
	return 0;
}
