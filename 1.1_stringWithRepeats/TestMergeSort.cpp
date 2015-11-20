/* A main program file for testing the mergeSort class
 * A series of unit tests on the mergeSort functions
 * MergeStrTest and MergeSort
 *
 * MergeStrTest:
 * Takes two strings assumed to be sorted
 * in alphabetical order and merges those two string's 
 * characters together in alphabetical order. This is
 * part of the merge sort algorithm.
 * 
 * MergeSort
 * This is the full merge sort alogorithm. One string
 * is passed in and the return string is sorted alphabetically
 * using the merge sort algorithm
 * Date: 10/24/15 
 */

#include "MergeSort.h"
#include <string>
#include <iostream>

using namespace std;

//Takes the results of the function and displays the
//results of the test
//Returns if test was successful or not
bool mergeStrTestResults(string leftStr, string rightStr,
                         string expected, string output){
    //The return value
    //Will be true if the output of MergeStrTest matches
    //the expected value
    bool testSuccess = false;
    cout << "Testing MergeStrTest with leftStr as \"" <<
    leftStr << "\" and rightStr as \"" << 
    rightStr << "\"" << endl;

    cout << "Result of MergeStrTest is \"" << output << "\"" << endl;

    if(output == expected){
        testSuccess = true;
        cout << "Success!" << endl;
    }
    else{
        //testSuccess is already false. No need to
        //set it false
        cout << "Test failure" << endl;
    }

    //Extra return at the end of the test to give the
    //individual test results some spacing
    cout << endl;

    return testSuccess;
}

//Take the result of the MergeSortInitialize function
//and an expected values to print a message that says
//if the functiond worked as expected
bool mergeSortResults(string input, string output, string expected){
    bool testSuccess = false;

    //Initial message
    cout << "Testing MergeSortInitialize function" << endl;
    //State what the input of the function was
    cout << "The input string was " << input << endl;
    //State what the output was
    cout << "The output of the function was " << output << endl;
    //Do the comparison
    if(output == expected){
        //If the comparison is equal print a success message
        //and set test success value to true
        cout << "Success!" << endl;
        testSuccess = true;
    }
    else
    {
        //If the comparison fails than the test failed. Print
        //the failure messages and set the test success value
        //to false
        cout << "Test failed" << endl;
        testSuccess = false;
    }

    //Extra return to space out individual tests
    cout << endl;

    //return the test success boolean
    return testSuccess;

}

int main(int argc, char** argv){
    //Test MergeStrTest
    //Create variables for all MergeStrTest tests
    string leftTest, rightTest, expected, output;
    MergeSort merge;
    bool totalSuccess = true;

        
    //Test 1
    //Arrane
    leftTest = "ace";
    rightTest = "bdf";
    expected = "abcdef";
    //Act
    output = merge.MergeStrTest(leftTest, rightTest);
    //Assert
    totalSuccess &= mergeStrTestResults(leftTest, rightTest, expected, output);
        


    //Test 2
    //Arrange
    leftTest = "xyz";
    rightTest = "XYZ";
    expected = "XYZxyz";
    //Act
    output = merge.MergeStrTest(leftTest, rightTest);
    //Assert
    totalSuccess &= mergeStrTestResults(leftTest, rightTest, expected, output);


    
    //Test 3
    //Arrange
    leftTest = "14tyZ";
    rightTest = "23uz";
    expected = "1234tuyZz";    
    //Act
    output = merge.MergeStrTest(leftTest, rightTest);
    //Assert
    totalSuccess &= mergeStrTestResults(leftTest, rightTest, expected, output);    
    

    if(totalSuccess){
        cout << "All MergeStrTest tests successful" << endl << endl;
    }
    
    //Extra returns to give the tests room
    cout << endl << endl << endl;
    //Reset success boolean for MergeSortInitialize tests
    totalSuccess = false;
    
    //Test MergeSortInitialize
    //Create MergeSortInitialize tests
    string inputTest;
    
    //Test 1
    //Arrange
    inputTest = "dcba";
    expected = "abcd";
    //Act
    output = merge.MergeSortInitialize(inputTest);
    //Assert
    totalSuccess &= mergeSortResults(inputTest, output, expected);
    
    
    //Test 2
    //Arrange
    inputTest = "tczby";
    expected = "bctyz";
    //Act
    output = merge.MergeSortInitialize(inputTest);
    //Assert
    totalSuccess &= mergeSortResults(inputTest, output, expected);


    //Test 3
    //Arrange
    inputTest = "52TtA8aGhU";
    expected = "258AGTUaht";
    //Act
    output = merge.MergeSortInitialize(inputTest);
    //Assert
    totalSuccess &= mergeSortResults(inputTest, output, expected);
    return 0;
}

