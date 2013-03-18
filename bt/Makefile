CC = gcc
CPP = g++
all: test_bt interview test_serialize_deserialize_bt

test_bt: test_bt.c binary_tree_util.h  binary_tree_print.h binary_tree.h
	$(CC) -o $@ $^ -lm

interview: interview_questions.c interview_questions.h binary_tree_print.h binary_tree_util.h binary_tree.h binary_treelr_util.h 
	$(CPP) -o $@ $^ -lm -g -std=c++0x
	#-Wno-write-strings

test_serialize_deserialize_bt: test_serialize_deserialize_bt.cpp serialize_deserialize_bt.h binary_tree.h binary_tree_util.h binary_tree_print.h
	$(CPP) -o $@ $^ -std=c++0x 


clean:
	rm test_bt interview test_serialize_deserialize_bt
