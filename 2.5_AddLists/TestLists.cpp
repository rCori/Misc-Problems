/* TestLists.cpp
 * Main file program for testing all of the functions in the
 * LinkedList class that are not AddIntList or the private
 * recursive helper function addIntListRecursive. Everything
 * being tested here should look like testing of standard
 * doubely linked list implementation.
 */

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <sstream>

//#define TESTEXCEPTION

enum TestType{
    OTHER = 0,
    CONSTRUCTOR,
    ADD,
    GETAT
};

bool StringTestVerification(std::string actual, std::string expected,
                            TestType testType){
    
    //Make a boolean flag for success or failure of the test
    bool successFlag = false;

    //Print what type of test this is
    switch(testType){
    //A test that does not fall into any of the other
    //categories
    case OTHER:
        std::cout << "This test is for something miscelaneous"
            << std::endl;
        break;
    //Testing the constructor
    case CONSTRUCTOR:
        std::cout << "Testing construction of LinkedList" << std::endl;
        break;
    //Testing the Add function
    case ADD:
        std::cout << "Testing LinkedList::Add" << std::endl;
        break;
    //Testing the GetAt function
    case GETAT:
        std::cout << "Testing LinkedList::GetAt" << std::endl;
    //For good form, make a default case that does nothing
    default:
        break;
    };

    //State what the expected and actual values are
    std::cout << "Expected value is \"" << expected << "\""
        << " and actual value is \"" << actual << "\"" << std::endl;
    
    //If the actual value is equal to the expected, state that
    //in a message and set the success flag to true
    if(expected == actual){
        //Success message
        std::cout << "Success!" << std::endl;
        //Set success flag
        successFlag = true;
    }
    //If expected is not equal to actual then the test failed
    else{
        //print message to state failure
        std::cout << "Test failed" << std::endl;
    }
    //Return success flag
    return successFlag;
}

int main(int argc, char** argv){
    //Test construction of a LinkedList
    //Make all the variabled needed for testing
    std::string expected, output;
    std::ostringstream ostream;
    bool totalTestSuccess = true;
    TestType testType = CONSTRUCTOR;
    
    //Test1
    //Arrange
    LinkedList<int> list1;
    expected = "";
    //Act
    ostream << list1;
    output = ostream.str();
    ostream.clear();    
    //Assert
    totalTestSuccess &= StringTestVerification(output, expected,
                                               testType);    


    //Test2
    //Arrange
    LinkedList<char> list2 = LinkedList<char>('a');
    expected = "a";
    //Act
    ostream << list2;
    output = ostream.str(); 
    ostream.str("");
    //Assert 
    totalTestSuccess &= StringTestVerification(output, expected,
                                               testType);

    //Test3
    //Arrange
    std::string input = "test";
    LinkedList<std::string> list3 = LinkedList<std::string>(input);
    expected = "test";
    //Act
    ostream << list3;
    output = ostream.str(); 
    ostream.str("");
    //Assert 
    totalTestSuccess &= StringTestVerification(output, expected,
                                               testType);

    //Testing Add function now
    //Make some whitespace to make room for new tests
    std::cout << std::endl << std::endl;
    
    //Change the test type to Add
    testType = ADD;

    //Test4
    //Arrange
    LinkedList<char> list4 = LinkedList<char>('b');
    expected = "b -> a -> s -> s";
    //Act
    list4.Add('a');
    list4.Add('s');
    list4.Add('s');
    ostream << list4;
    output = ostream.str();
    ostream.str("");
    //Assert
    totalTestSuccess &= StringTestVerification(output, expected,
                                               testType);

    //Test5
    //Arrange
    LinkedList<float> list5 = LinkedList<float>(1.2);
    expected = "1.2 -> 1.3 -> 1.4 -> 1.5";
    //Act
    list5.Add(1.3);
    list5.Add(1.4);
    list5.Add(1.5);
    ostream << list5;
    output = ostream.str();
    ostream.str("");
    //Assert
    totalTestSuccess &= StringTestVerification(output, expected,
                                               testType);


    //Testing GetAt function now
    //Make some whitespace to make room for new tests
    std::cout << std::endl << std::endl;
    
    //Change the test type to Add
    testType = GETAT;

    //Test6
    LinkedList<int> list6 = LinkedList<int>(1);
    expected = "3";
    //Act
    list6.Add(5);
    list6.Add(3);
    list6.Add(14);
    list6.Add(9);
    ostream << list6.GetAt(2);
    output = ostream.str();
    ostream.str("");
    //Assert
    totalTestSuccess &= StringTestVerification(output, expected,
                                               testType);

    #ifdef TESTEXCEPTION
    //Test exception1
    LinkedList<char> listException1 = LinkedList<char>('a');
    expected = "t";
    //Act
    listException1.Add('y');
    listException1.Add('q');
    listException1.Add('t');
    //out of bounds, will throw an exception
    ostream << listException1.GetAt(10);
    output = ostream.str();
    ostream.str("");
    //Assert 
    totalTestSuccess &= StringTestVerification(output, expected,
                                               testType);

    
    //Test exception1
    LinkedList<double> listException2 = LinkedList<double>(4.0);
    expected = "0.0";
    //Act
    listException2.Add(2.5);
    listException2.Add(0.0);
    listException2.Add(3.1);
    //out of bounds, will throw an exception
    ostream << listException2.GetAt(-2);
    output = ostream.str();
    ostream.str("");
    //Assert 
    totalTestSuccess &= StringTestVerification(output, expected,
                                               testType);
    #endif

    //Make whitespace for final test results
    std::cout << std::endl << std::endl;

    //Check if all tests pass
    if(totalTestSuccess){
        //All tests successful. Print success message
        std::cout << "All tests successful" << std::endl;
    }
    //Some test failed
    else{
        //print test failure message
        std::cout << "Some tests have failed" << std::endl;
    }

    return 0;
}
