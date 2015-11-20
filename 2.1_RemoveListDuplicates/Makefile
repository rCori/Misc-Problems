# A linked list implementation that has a function
# to remove duplicates

CC = g++

CFLAGS = -std=c++11 -g -Wall

default : main

main: RemoveDuplicates.cpp LinkedListNode.cpp LinkedListNode.h
	$(CC) $(CFLAGS) -o RemoveDuplicates RemoveDuplicates.cpp LinkedListNode.cpp LinkedListNode.h
	chmod +x RemoveDuplicates

test: TestLinkedList.cpp LinkedListNode.cpp LinkedListNode.h
	$(CC) $(CFLAGS) -o TestLinkedList TestLinkedList.cpp LinkedListNode.cpp LinkedListNode.h
	chmod +x TestLinkedList

clean:
	$(RM) *.o RemoveDuplicates TestLinkedList
