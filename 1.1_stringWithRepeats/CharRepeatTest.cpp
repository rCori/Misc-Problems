/* CharRepeatTest.cpp
 * This is the implementation of the MergeSort class for solving
 * the interview problem. The problem is "Implement an algorithm
 * to determine if a string has all unique characters. What if
 * you cannot use additional data structures?" My solution to 
 * the problem is to just sort the string alphabetically and then
 * see if two repeat characters are next to each other in the
 * string. I will do this by having two indices in the string
 * iterate through at the same time. If at any point those indices
 * point to the same char, then a repeat has been found.
 * Date: 10/27/15
 * Author: Ryan Cori
 */

#include <string>
#include <iostream>
#include "MergeSort.h"

using namespace std;

//Test if inputStr contains repeat char. If it doesn't then print
//a message saying so. If it does, print a message saying a repeat
//has been found, what character it is, and return false.
bool CharRepeatTest(string inputStr){
    //Create a MergeSort instance to perform the merge
    //sort operation
    MergeSort merge;
    //Create a string to store output and assign it
    //to the result of the merge sort
    string output;
    output = merge.MergeSortInitialize(inputStr);
    //Create a bool to store if we found a repeat while
    //looping over the string
    bool resultBool;
    //Create a char to store the char that was found
    //repeating if one was found at all.
    char repeatChar;
    //Create two indices to iterate through the string
    unsigned int firstIndex = 0, secondIndex = 1;
    //Iterate through the string
    while(secondIndex != output.length()){
        //Test if the two current chars are the same
        if(output[firstIndex] == output[secondIndex]){
            //Repeat found
            //Print message
            cout << "Repeated character found" << endl;
            //Get the character and continue the message
            repeatChar = output[firstIndex];
            cout << " The character " << repeatChar << " was repeated" << endl;
            //Set the test result boolean to true
            resultBool = true;
        }
        //If a match was found, break from the loop
        if(resultBool){
            break;
        }
        //Increment both indices
        firstIndex++;
        secondIndex++;
    }
    //If the second index has run off the end, then no repeat
    //was ever found.
    if(secondIndex == output.length()){
        //Print a message that there is no repeat char in the string
        //and set the test result boolean to false
        cout << "String contains no repeated characters" << endl;
        resultBool = false;
    }
    //Return the result
    return resultBool;
}

bool CharRepeatTestResults(string inputStr, bool output, bool expected){
    //Create a test result boolean
    bool testResult = false;
    //Print a message stating what the tested string was
    cout << "The input string was \"" << inputStr << "\"" << endl;
    //If output matches what we expected, test result is true
    if(expected == output){
        cout << "Success!" << endl;
        testResult = true;
    //Otherwise test result is false
    } else {
        cout << "Test failed" << endl;
        testResult =  false;
    }
    //Create some extra returns to space out the tests
    cout << endl;
    //Return the test result
    return testResult;
}

int main(int argc, char** argv){
    //Using CharRepeatTest to detect duplicate characters
    //in strings

    //Create an input string varible to reuse and two
    //bools for ouput and expected
    string input;
    bool output, expected;

    //A bool to keep track of the running results of all of the tests
    bool totalResults = true;
    
    //Test 1
    
    //Arrange
    input = "abcdefg";
    expected = false;
    //Apply
    output = CharRepeatTest(input);
    //Assert
    totalResults &= CharRepeatTestResults(input, output, expected);


    //Test 2
    
    //Arrange
    input = "qwertyq";
    expected = true;
    //Apply
    output = CharRepeatTest(input);
    //Assert    
    totalResults &= CharRepeatTestResults(input, output, expected);


    //Test 3
    
    //Arrange
    input = "1238Aadfg";
    expected = false;
    //Apply
    output = CharRepeatTest(input);
    //Assert
    totalResults &= CharRepeatTestResults(input, output, expected);

    //Test 4
    
    //Arrange
    input = "ituwpsu";
    expected = true;
    //Apply
    output = CharRepeatTest(input);
    //Assert
    totalResults &= CharRepeatTestResults(input, output, expected);

    //Test 5
    
    //Arrange
    input = "zzzzzzz";
    expected = true;
    //Apply
    output = CharRepeatTest(input);
    //Assert
    totalResults &= CharRepeatTestResults(input, output, expected);

    //print a message if all test results were successful or not
    if(totalResults){
        cout << "All tests passed!" << endl;
    } else {
        cout << "Some tests have failed" << endl;
    }
}
