#implementation of a stack that keeps track of the minimum element in the
#stack and can return it with the function Min. Pop, Push, and Min are
#implemented to run in O(1) time

CC=g++

CFLAG= -std=c++11 -g -Wall

default: main

main: MinStackTest.cpp MinStack.cpp MinStack.h
	clear
	$(CC) $(CFLAG) -o MinStackTest MinStackTest.cpp MinStack.cpp MinStack.h
	chmod +x MinStackTest
	./MinStackTest > testLog.txt
	cat testLog.txt


clean:
	$(RM) *.o MinStackTest
