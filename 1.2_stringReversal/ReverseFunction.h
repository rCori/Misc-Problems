/* ReverseFunction.h
 * Header file and definition for the two non class
 * functions that are used in string reversal. The
 * two functions are swapInArray which is a template
 * function to swap values in an array of any type and
 * reverse which reverses the ordering of characters
 * in a char*. As expected the the implementation of
 * reverse will be in ReverseFunction.cpp. However
 * for implementing swapInArray, because it uses
 * a template, we will actually define that in a
 * seperate file called ReverseFunctionTemplate.cpp.
 * That will be included at the bottom of this header.
 * We have to do this in order for the compiler to
 * generate all of the template functions required,
 * defintion and implementation must be accessable to
 * the compiler when generating the template functions.
 * Author: Ryan Cori
 * Date: 10/28/15
 */

//Header guard
#ifndef _REVERSE_FUNC_
#define _REVERSE_FUNC_

#include <iostream>

using namespace std;

//Templated function for swapping two values in any array
//Does bounds checking with asserts to make sure the two
//chosen value indices are in range
template<typename T>
void swapInArray(T* inputArray, int x, int y);


//public function for reversing a char*
void reverse(char* str);

#include "ReverseFunctionTemplates.cpp"

#endif
