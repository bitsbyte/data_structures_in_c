#include "linked_list_util.h"

void die()
{
	printf("usage : kreverse_mtraverse ll_size k m \n");
	exit(1);
}

int main(int argc, char* argv[])
{
	if( argc < 4 )
		die();
	
	ll *list = random_list(atoi(argv[1]));
	if( list ) {
		int k = atoi(argv[2]);
		int m = atoi(argv[3]);
		print_list(list);
		printf("after k reverse m traverse: \n");
		kreverse_mtraverse(&list, k, m);
		print_list(list);
	}
	return 0;	
}
