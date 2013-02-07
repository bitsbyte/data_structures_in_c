#include "linked_list_util.h"

main(int argc, char* argv[])
{
	ll *list = random_list(atoi(argv[1]));
	if( list ) {
		print_list(list);
		printf("reversed list: \n");
		reverse_list(&list);
		print_list(list);
	}
	return 0;
}
