# Makefile for a small program to implement a solution to a
# sample interview question. The question is:
# Implement a function void reverse(char* str) in C or C++
# which reverses a null-terminated string.
# I am of course using c++. Only two build targets will be
# to make the program and to clean it up

CC=g++
CSTD = -std=c++11
CFLAGS= -g -Wall

default : ReverseTest

ReverseTest: ReverseTest.cpp ReverseFunction.cpp ReverseFunction.h ReverseFunctionTemplates.cpp
	$(CC) $(CSTD) $(CFLAGS) -o ReverseTest ReverseTest.cpp ReverseFunction.cpp ReverseFunction.h ReverseFunctionTemplates.cpp
	chmod +x ReverseTest

clean:
	$(RM) *.o ReverseTest
