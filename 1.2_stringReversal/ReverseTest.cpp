/* ReverseTest.cpp
 * For testing the functions defined in 
 * ReverseFunction.h. This will use the public
 * debug build version of swapInArray to test
 * if it swaps two array values. reverse will
 * also be tested to see if input char*'s are
 * actually reversed.
 * Author: Ryan Cori
 * Date: 10/28/15
 */

#include <iostream>
#include "string.h"

#include "ReverseFunction.h"

using namespace std;

//#define TESTASSERT

enum TestType{
    swapInArray_Test = 0,
    reverse_Test
};

bool TestResults(char* input, char* inputCpy, char* expected, enum TestType testType){
    //Make a test result boolean
    bool testResults = false;
    //State what the test is
    switch(testType){
    //Testing swapInArray
    case swapInArray_Test:    
        cout << "Testing swapInArray" << endl;
        break;
    //Testing reverse
    case reverse_Test:
        cout << "Testing reverse" << endl;
        break;
    default:
        break;
    }
    //State the what the input was and what it is now
    cout << "Input was \"" << inputCpy << "\" and output was \"" <<
    input << "\"" << endl;
    //Make the comparison of the output and the expected value
    if(strcmp(input, expected) == 0){
        //The test succeeded
        //Print a success message and set the test results to true
        cout << "Success!" << endl;
        testResults = true;
    } else {
        //Test failed, just print the failure message
        //and set the test result to false
        cout << "Test failed" << endl;
        testResults = false;
    }
    return testResults;
}



int main(int argc, char** argv){
    //Testinig swapInArray
    
    //declare all of the variables needed for
    //all of the tests
    char* input = new char;
    char* inputCpy = new char;
    char* expected = new char;
    int x, y;
    bool totalSuccess = true;
    enum TestType testType = swapInArray_Test;
    //Test 1
    //Arrange
    strcpy(input, "abcd");
    strcpy(inputCpy, "abcd");
    strcpy(expected, "dbca");
    x = 0;
    y = 3;
    //Act
    swapInArray(input,x,y);
    //Assert   
    totalSuccess &= TestResults(input, inputCpy, expected, testType);


#ifdef TESTASSERT
    //Test 2
    //I expect and assertion to fail here
    //Arrange
    strcpy(input, "xyz");
    strcpy(inputCpy, "xyz");
    //This is not really expected. The expected
    //behaviour is an assertion is thrown.
    strcpy(expected, "yzx");
    x = 0;
    y = 3;
    //Act
    swapInArray(input,x,y);
    //Assert   
    totalSuccess &= TestResults(input, inputCpy, expected, testType);
#endif

    
    //Test 3
    //Arrange
    strcpy(input, "qwerty");
    strcpy(inputCpy, "qwerty");
    strcpy(expected, "qwrety");
    x = 2;
    y = 3;
    //Act
    swapInArray(input,x,y);
    //Assert   
    totalSuccess &= TestResults(input, inputCpy, expected, testType);

    //Make extra spacing between the two sets of tests
    cout << endl;
    cout << endl;

    //Testing reverse function
    //Change the Test type for printing results
    testType = reverse_Test;
    
    //Test4
    strcpy(input, "lefty");
    strcpy(inputCpy, "lefty");
    strcpy(expected, "ytfel");   
    //Act
    reverse(input);
    //Assert
    totalSuccess &= TestResults(input, inputCpy, expected, testType);

    //If all tests passed display a message saying so
    if(totalSuccess){
        cout << "All tests passed" << endl;
    }
    //If some of the tests did not pass
    else{
        cout << "Some tests have failed" << endl;
    }


    //Test5
    strcpy(input, "rightey");
    strcpy(inputCpy, "rightey");
    strcpy(expected, "yethgir");   
    //Act
    reverse(input);
    //Assert
    totalSuccess &= TestResults(input, inputCpy, expected, testType);

    //If all tests passed display a message saying so
    if(totalSuccess){
        cout << "All tests passed" << endl;
    }
    //If some of the tests did not pass
    else{
        cout << "Some tests have failed" << endl;
    }


    //Test6
    strcpy(input, "Cori");
    strcpy(inputCpy, "Cori");
    strcpy(expected, "iroC");   
    //Act
    reverse(input);
    //Assert
    totalSuccess &= TestResults(input, inputCpy, expected, testType);

    //If all tests passed display a message saying so
    if(totalSuccess){
        cout << "All tests passed" << endl;
    }
    //If some of the tests did not pass
    else{
        cout << "Some tests have failed" << endl;
    }


    //Test7
    strcpy(input, "123456789");
    strcpy(inputCpy, "123456789");
    strcpy(expected, "987654321");   
    //Act
    reverse(input);
    //Assert
    totalSuccess &= TestResults(input, inputCpy, expected, testType);

    //If all tests passed display a message saying so
    if(totalSuccess){
        cout << "All tests passed" << endl;
    }
    //If some of the tests did not pass
    else{
        cout << "Some tests have failed" << endl;
    }


    //Test8
    strcpy(input, "Coo1Guy95");
    strcpy(inputCpy, "Coo1Guy95");
    strcpy(expected, "59yuG1ooC");   
    //Act
    reverse(input);
    //Assert
    totalSuccess &= TestResults(input, inputCpy, expected, testType);

    //If all tests passed display a message saying so
    if(totalSuccess){
        cout << "All tests passed" << endl;
    }
    //If some of the tests did not pass
    else{
        cout << "Some tests have failed" << endl;
    }

    //cleanup
    delete input;
    delete inputCpy;
    delete expected;


    return 0;
}
