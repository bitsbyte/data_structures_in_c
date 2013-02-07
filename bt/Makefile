CC = gcc
all: test_bt

test_bt: test_bt.c binary_tree_util.h  binary_tree_print.h binary_tree.h
	$(CC) -o $@ $^ -lm

clean:
	rm test_bt
