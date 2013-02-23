#ifndef _ARRAY_UTIL_H
#define _ARRAY_UTIL_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//#define MAX(a,b) ( ((a) > (b)) ? (a) : (b) )

int * create_random_array(int size, int min, int max)
{
	int i ;
	srand(time(NULL));
	int *a = (int *) malloc(size * sizeof(int));
	for( i = 0; i < size; ++i)
		a[i] = (int) (((float)rand()/(float)RAND_MAX)*(max-min) + min);
	return a;	
}

void print(int *a, int size)
{
	int i;
	for( i = 0; i < size; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

int max_contiguous_subarray_sum(int *a, int size, int *start, int *end)
{
	int	maxsofar = 0;
	int	maxendinghere = 0;
	int maxendinghere_begin = 0;
	int maxsofar_begin = -1, maxsofar_end = -1;
	int i;

	for( i = 0 ; i < size ; ++i)
	{
		//maxendinghere = max(0, maxendinghere + a[i]);
		if( 0 > (maxendinghere + a[i])) {
			maxendinghere_begin = -1;
			maxendinghere = 0;
		} else {
			//  udpate maxendinghere_begin when maxendinghere is transitioning from 
			//  0 to a +ve value
			if( maxendinghere == 0 && (maxendinghere + a[i] > 0))
				maxendinghere_begin = i;
			maxendinghere = maxendinghere + a[i];
		}
	
		//maxsofar = max(maxsofar, maxendinghere);
		if( maxsofar < maxendinghere ) {
			maxsofar_begin = maxendinghere_begin;
			maxsofar_end = i;
			maxsofar = maxendinghere;
		}
	}
	
	*start = maxsofar_begin;
	*end = maxsofar_end;
	return maxsofar;
}

// Knuth's Shuffle
void shuffle(int *a, int size)
{
	if( a != NULL && size > 1 )
	{
		int i, random_idx, temp;

		srand(time(NULL));
		for ( i = 0; i < size -1 ; ++i)
		{
			random_idx =  (int)(((float)rand()/(float)RAND_MAX)*( (size -1) - (i+1) )  + (i+1));
			temp = a[i];
			a[i] = a[random_idx];
			a[random_idx] = temp;
		}
	}
}

int** alloc_2d_array(int row, int col)
{
	if( row <= 0 || col <= 0 )
		return NULL;

	int **a = (int**) calloc(row, sizeof(int*)); //new int*[row]();
	int i;
	for( i = 0 ; i < row ; ++i)
		a[i] = (int*) calloc(col, sizeof(int)); //new int[col]();
	return a;
}

void dealloc_2d_array(int **a, int row)
{
	if(!a || row <= 0 ) 
		return;
	int i;
	for( i = 0 ; i < row; ++i)
		free(a[i]);//delete [] a[i];
	free(a); // delete [] a;
}

void print_2d_array(int **a, int row, int col)
{
	if(!a || row <= 0 || col <= 0 )
		return;
	printf("\n");
	int i,j;
	for(  i = 0 ; i < row; ++i)
	{
		for( j = 0 ; j < col; ++j)
			printf(" %d\t", a[i][j]);
		printf("\n");
	}

}

void insertionsort(int *ar, int ar_size) 
{
	if( !ar || ar_size < 0)
		return;

    for(int i = 1; i < ar_size; ++i)
    {
        int temp = ar[i];
        int j = i-1;
        while(j >= 0 && ar[j] > temp)
        {
           ar[j+1] = ar[j];
            --j;
        }   
        ar[j+1] = temp;
    }
}



void swap(int *a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// O(n) in-place partition for quicksort
int partition(int *a, int size)
{
    if( size == 1)
        return 0;
    
    int small = -1;
    int current = 0;
    int pivot = a[0];
    
    swap(a,0, size-1);
    
    while( current <= size-2)
    {
        if( a[current] < pivot )  
        {
            ++small;
            swap(a,current, small);
        }
        ++current;
    }
    
    ++small;
    swap(a,small,size-1);
    return small;
}


void quicksort(int *a, int size) {
    
    if( size <= 1)
        return;
    
    int partition_index = partition(a,size);
    quicksort(a, partition_index);
    quicksort(a+partition_index+1, size -(partition_index+1));    
}

#endif

