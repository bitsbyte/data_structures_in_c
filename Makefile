CC= gcc
#SRC = $(wildcard *.c) $(wildcard *.h)
all: reverse_list kreverse_mtraverse merge_two_sorted_half_into_one find_intersection max_contiguous_sum

reverse_list: reverse_list.c linked_list_util.h linked_list.h
	$(CC) -o $@ $^

kreverse_mtraverse: kreverse_mtraverse.c linked_list_util.h linked_list.h
	$(CC) -o $@ $^

merge_two_sorted_half_into_one: merge_two_sorted_half_into_one.c  linked_list_util.h linked_list.h
	$(CC) -o $@ $^

find_intersection:find_intersection.c linked_list_util.h linked_list.h
	$(CC) -o $@ $^

max_contiguous_sum: maximum_contiguous_sum.c linked_list_util.h linked_list.h array_util.h
	$(CC) -o $@ $^ -std=c99

clean:
	rm reverse_list kreverse_mtraverse merge_two_sorted_half_into_one find_intersection max_contiguous_sum
