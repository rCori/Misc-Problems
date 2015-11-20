# Question 1.1 
# Implement an algorithm to determine if a string has
# all unique characters. What if you cannot use additional
# data structures.

CC = g++
CFLAGS = -g -Wall

default: main

main: CharRepeatTest.cpp MergeSort.cpp MergeSort.h
	$(CC) $(CFLAGS) -o CharRepeatTest CharRepeatTest.cpp MergeSort.cpp MergeSort.h
	chmod +x CharRepeatTest

testMergeSort: TestMergeSort.cpp MergeSort.cpp MergeSort.h
	$(CC) $(CFLAGS) -o TestMergeSort TestMergeSort.cpp MergeSort.cpp MergeSort.h
	chmod +x TestMergeSort

clean:
	$(RM) *.o TestMergeSort CharRepeatTest
