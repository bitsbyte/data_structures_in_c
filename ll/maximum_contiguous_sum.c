#include<stdio.h>
#include "array_util.h"


void die()
{
	printf("usage: maximum_contiguous_sum array_size min max\n");
	exit(1);
}

int main(int argc, char *argv[])
{
	if( argc < 4 )
		die();
	int size = atoi(argv[1]);
	int min = atoi(argv[2]);
	int max = atoi(argv[3]);
		
	int *a = random(size, min, max);
	int start,end;
	//int a[] = {31,-41,59,26,-53,58,97,-93,-23,84}; // answer 187 , start =2 , end = 6
	int maxsum = max_contiguous_subarray_sum(a, size, &start, &end);
	print(a,size);
	printf("max contiguous subarray sum: %d\n", maxsum);
	printf("start: %d end: %d\n",start,end);
	return 0;	
}
