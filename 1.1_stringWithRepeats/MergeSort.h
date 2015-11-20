//mergeSort.h
/*
* I need to define two functions this class will do.
* I do not need to define a constructor, the default will
* be fine.
* Purpose of this class is to practice handweriting mergesort
* for the purpose of answering a standard style interview question
* I will have one public function to start the process and then two
* functions that will be called recursively.
* One recursive function, mergeSortSplit, checks if the string input
* is one character large and if not, will split the string in half
* and call the function again on the two halves.
* When this function returns from process both halves, the other
* function, mergeStrings, will merge them back together, character
* by character.
* Author: Ryan Cori
* Date: 10/22/15
*/

#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_
#include <string>

#define DEBUGBUILD

class MergeSort{
public:
  //Function for client user to call to do mergesort
  //All other functions are intended to be used internally
  std::string MergeSortInitialize(std::string inputStr);
#ifdef DEBUGBUILD
  //Gives public access for calling internal function 
  std::string MergeStrTest(std::string leftStr, std::string rightStr);
#endif
private:
  std::string mergeSortSplit(std::string inputStr);
  std::string mergeStrings(std::string leftStr, std::string rightStr);
};

#endif
