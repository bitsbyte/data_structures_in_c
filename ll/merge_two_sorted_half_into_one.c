#include<stdio.h>
#include "linked_list_util.h"

ll* list1()
{
	return	node(4,node(5,node(1,node(2,0))));
}

ll* list2()
{
	return  node(1,node(5,node(7,node(9,node(11,node(2,node(4,node(6,0))))))));
}

ll* list3()
{
	return node(1,node(2,node(3,node(4,0))));	
}

ll* list4()
{
	return node(1,0);
}

ll* list5()
{
	return node(3,node(1,0));
}


int main()
{
	ll *list;
	
	list = list1();
	print_list(list);
	merge_two_sorted_half_into_one(&list);
	printf("after merge:  ");
	print_list(list);
	
	list = list2();
	print_list(list);

	merge_two_sorted_half_into_one(&list);
	printf("after merge: ");	print_list(list);

	list = list3();
	print_list(list);

	merge_two_sorted_half_into_one(&list);
	printf("after merge: ");	print_list(list);

	list = list4();
	print_list(list);

	merge_two_sorted_half_into_one(&list);
	printf("after merge: ");	print_list(list);

	list = list5();
	print_list(list);

	merge_two_sorted_half_into_one(&list);
	printf("after merge: ");	print_list(list);

}
