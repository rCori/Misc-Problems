/* MinStackTest.cpp
 * Main program file for testing MinStackTest
 * Will functions Push, Pop, and Min
 * Author: Ryan
 * Date: 11/5/15
 */

#include "MinStack.h"
#include <iostream>
#include <string>
#include <sstream>

enum TestType{
    CONSTRUCTION = 0,
    PUSH,
    POP,
    MIN
};

bool TestVerification(std::string expected, std::string output,
                      TestType testType){
    //Create a success boolean flag
    bool successFlag = false;
    //Print what type of test this is
    switch(testType){
    //Testing the constructor
    case CONSTRUCTION:
        //print a message for testing the constructor
        std::cout << "Testing the constructor" << std::endl;
        break;
    //Testing the Push function
    case PUSH:
        //print a message for testing the constructor
        std::cout << "Testing Push function" << std::endl;
        break;
    //Testing the Pop function
    case POP:
        //print a message for testing the constructor
        std::cout << "Testing Pop function" << std::endl;
        break;
    //Testing the Min function
    case MIN:
        //print a message for testing the constructor
        std::cout << "Testing Min function" << std::endl;
        break;
    default:
        break;
    }
    //State what the expected value and output values are
    std::cout << "Expected value is " << std::endl << expected
        << std::endl << "and actual output is" << std::endl
        << output  << std::endl;

    //check if excepted is equal to output, if so the test passed
    if(expected == output){
        //Print a message that
        std::cout << "Success!" << std::endl;
        //Set the test result flag
        successFlag = true;
    }
    //Test failed
    else{
        //print a message for test failure
        std::cout << "Test failure" << std::endl;
    }

    return successFlag;
}

int main(int arc, char** argv){

    //Testing the constructor
    //Create all the variables I need for tests
    std::string output, expected;    
    std::ostringstream ostream;
    bool allTestsSuccessful = true;
    TestType testType = CONSTRUCTION;

    
    //Test 1
    //Arrange
    MinStack<float> minStack1 = MinStack<float>();
    //Act
    ostream << minStack1;
    output = ostream.str();
    ostream.str("");
    //Now create expected
    expected = "Main Stack\n\nMinimum Stack\n";
    //Assert
    allTestsSuccessful = TestVerification(expected, output, testType);

   
    //Testing the Push function
    testType = PUSH;
    //Space between the test types
    std::cout << std::endl << std::endl;
    
    //Test2
    //Arrange
    MinStack<int> minStack2 = MinStack<int>();
    //Act
    minStack2.Push(4);
    minStack2.Push(2);
    minStack2.Push(7);
    ostream << minStack2;
    output = ostream.str();
    expected = "Main Stack\n7 -> 2 -> 4\nMinimum Stack\n2 -> 4";
    ostream.str("");
    //Assert
    allTestsSuccessful = TestVerification(expected, output, testType); 
    
    //Make space
    std::cout << std::endl;

    //Test3   
    //Arrange
    MinStack<double> minStack3 = MinStack<double>();
    //Act
    minStack3.Push(9.95);
    minStack3.Push(2.4);
    minStack3.Push(6.6);
    minStack3.Push(1.3);
    ostream << minStack3;
    output = ostream.str();
    expected = "Main Stack\n1.3 -> 6.6 -> 2.4 -> 9.95\nMinimum Stack\n1.3 -> 2.4 -> 9.95";
    ostream.str("");
    //Assert
    allTestsSuccessful = TestVerification(expected, output, testType);
    
    //Testing Pop function
    testType = POP;
    //Make space
    std::cout << std::endl << std::endl;  


    //Test4   
    //Arrange
    MinStack<int> minStack4 = MinStack<int>();
    //Act
    minStack4.Push(9);
    minStack4.Push(2);
    minStack4.Push(6);
    minStack4.Pop();
    ostream << minStack4;
    output = ostream.str();
    expected = "Main Stack\n2 -> 9\nMinimum Stack\n2 -> 9";
    ostream.str("");
    //Assert
    allTestsSuccessful = TestVerification(expected, output, testType); 

    //Make space
    std::cout << std::endl;

    //Test5   
    //Arrange
    MinStack<float> minStack5 = MinStack<float>();
    //Act
    minStack5.Push(5.4);
    minStack5.Push(1.2);
    minStack5.Push(6.5);
    minStack5.Push(10.0);
    minStack5.Push(8.5);
    minStack5.Pop();
    minStack5.Pop();
    ostream << minStack5;
    output = ostream.str();
    expected = "Main Stack\n6.5 -> 1.2 -> 5.4\nMinimum Stack\n1.2 -> 5.4";
    ostream.str("");
    //Assert
    allTestsSuccessful = TestVerification(expected, output, testType); 

    //Testing Min function
    testType = MIN;
    //Make space for tests
    std::cout << std::endl << std::endl;

    //Test5   
    //Arrange
    MinStack<float> minStack6 = MinStack<float>();
    //Act
    minStack6.Push(1.2);
    minStack6.Push(2.4);
    minStack6.Push(3.6);
    minStack6.Pop();
    ostream << minStack6.Min();
    output = ostream.str();
    expected = "1.2";
    ostream.str("");
    //Assert
    allTestsSuccessful = TestVerification(expected, output, testType);

    //Spacing for tests
    std::cout << std::endl;

    //Test6
    //Arrange
    MinStack<int> minStack7 = MinStack<int>();
    //Act
    minStack7.Push(5);
    minStack7.Push(6);
    minStack7.Push(8);
    minStack7.Push(2);
    minStack7.Push(2);
    minStack7.Push(2);
    minStack7.Pop();
    minStack7.Pop();
    ostream << minStack7.Min();
    output = ostream.str();
    expected = "2";
    ostream.str("");
    //Assert
    allTestsSuccessful = TestVerification(expected, output, testType);
 
    //Print message if all tests were successful
    if(allTestsSuccessful){
        std::cout << "All tests passed!" << std::endl;
    }
    //Some tests have failed
    else{
        std::cout << "Some tests have failed" << std::endl;
    }
    
    
}
