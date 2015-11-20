#Interview question 2.5
#You have two numbers represented by a linked list where each node contains
#a single digit. The digits are stored in reverse order, such that the 1's
#digit is at the head of the list. Write a function that adds the two numbers
#and returns the sum as a linked list.
#The linked list is implemented generically. The function for adding them
#is a static member of that class but is not generic

CC = g++

CFLAGS = -std=c++11 -g -Wall

default: main

main: AddLists.cpp LinkedList.h
	$(CC) $(CFLAGS) -o AddLists AddLists.cpp LinkedList.h
	chmod +x AddLists

test: TestLists.cpp LinkedList.h
	clear
	$(CC) $(CFLAGS) -o TestLists TestLists.cpp LinkedList.h
	chmod +x TestLists
	./TestLists > testLog.log
	cat testLog.log
	rm TestLists

clean:
	$(RM) *.o AddLists TestLists
