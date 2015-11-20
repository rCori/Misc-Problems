/* ReverseFunction.cpp
 * Implementation of the functions defined in
 * ReverseFunction.h. That will be definitions for
 * only reverse. swapInArray is a template function, so
 * it's implementation will be part of a different file so it
 * can be included in the header below the defintion swapInArray
 * Author: Ryan Cori
 * Date: 10/28/15  
 */

#include <string>
#include <string.h>
#include "ReverseFunction.h"

using namespace std;


//Reverse the ordering of the characters of the char* str.
//Makes use of swapInArray. Use two indices to mark beginning
//and end of char array. Loop over swapping the two chars
//being pointed to and then move indices closer together
void reverse(char* str){
    //Make a strug fron the char* for easier handling
    string inputStr = string(str);
    //Make two unsigned ints for beginning and end index
    //of the string. Use .length() for the end of the string
    unsigned int start = 0;
    unsigned int end = inputStr.length()-1;
    //Loop while the start index comes before the end index
    while(start<end){
        //Swap two chars
        //First make a new char*
        char* charInputStr = new char[inputStr.length()+0];
        //Now use strcpy to copy over the characters from
        //inputStr into the char* charInputStr
        strcpy(charInputStr, inputStr.c_str());
        //Swap the current characters
        swapInArray(charInputStr, start, end);
        //Reassign the inputStr for keeping track of
        //the char*
        inputStr = string(charInputStr);
        //Move the indices closer together
        start++;
        end--;
        //cleanup this iteration of charInputStr
        delete charInputStr;
    }
    //Now copy over the characters from inputStr
    //into the char* str
    strcpy(str, inputStr.c_str());
    
}
