CC = gcc
CPP = g++
all: test_bt interview

test_bt: test_bt.c binary_tree_util.h  binary_tree_print.h binary_tree.h
	$(CC) -o $@ $^ -lm

interview: interview_questions.c interview_questions.h binary_tree_print.h binary_tree_util.h binary_tree.h binary_treelr_util.h 
	$(CPP) -o $@ $^ -lm -g -std=c++0x
	#-Wno-write-strings

clean:
	rm test_bt interview
