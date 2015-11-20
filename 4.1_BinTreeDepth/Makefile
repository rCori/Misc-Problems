# Implementation of a binary search tree that can return if it is
# balenced or not. A balneced tree is a tree where all leaf nodes
# have a difference in depth no more than 1.

CC= g++

CFLAG = -std=c++11 -g -Wall

default: main

main: BSTree.cpp BSTree.h BSTreeDepth.cpp
	clear
	$(CC) $(CFLAG) -o BSTreeDepth BSTreeDepth.cpp BSTree.cpp BSTree.h

clear:
	$(RM) *.o BSTreeDepth
