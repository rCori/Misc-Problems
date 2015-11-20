//Implementation of mergeSort class

#include "MergeSort.h"
#include <string>

using namespace std;


string MergeSort::MergeSortInitialize(string inputStr){
    //Call mergeSortSplit on the input string
    inputStr = mergeSortSplit(inputStr);
    return inputStr;
}

#ifdef DEBUGBUILD
string MergeSort::MergeStrTest(string leftStr, string rightStr){
    //All we do here is call mergeStrings and return it's value
    return mergeStrings(leftStr, rightStr);
}
#endif


string MergeSort::mergeSortSplit(string inputStr){
    //Test the size of the input string
    if(inputStr.length() != 1){
        //Find the middle of the string to split the
        //string at
        int splitIndex = inputStr.size()/2;
        //Now use substr to split the string into two evenly
        //sized left and right strings
        string leftStr = inputStr.substr(0, splitIndex);
        string rightStr = inputStr.substr(splitIndex);
        //Use this function reccursivl to split up the
        //two halves
        leftStr = mergeSortSplit(leftStr);
        rightStr =  mergeSortSplit(rightStr);
        //Merge the two halves together. Each half
        //will either be sorted or in order
        inputStr = mergeStrings(leftStr, rightStr);
    }
    return inputStr;
}


string MergeSort::mergeStrings(string leftStr, string rightStr){
    unsigned int leftIndex = 0;
    unsigned int rightIndex = 0;
    string returnStr;
    while(leftIndex != leftStr.length() ||
          rightIndex != rightStr.length())
    {
        //If right comes before left or we reached the
        //end of left but only if we have not reached the
        //end of the right string
        if((leftIndex == leftStr.length() ||
           rightStr[rightIndex] < leftStr[leftIndex])
            && rightIndex != rightStr.length()){
            //append character and increase index on
            //right string
            returnStr += rightStr[rightIndex];
            rightIndex++;
        } else {
            //append left character and increase index
            returnStr += leftStr[leftIndex];
            leftIndex++;
        }
    }
    return returnStr;    
}



