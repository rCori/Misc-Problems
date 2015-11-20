/* AddLists.cpp
 * Main program file for testing the LinkedList class function
 * AddIntLists. All other functions have a seperate file and
 * program for testing.
 * Author: Ryan Cori
 * Date: 11/4/15
 */

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <sstream>

bool AddListTestResults(std::string output, std::string expected){
    //Success flag boolean to return
    bool successFlag = false;
    //Message for what the test is
    std::cout << "Testing AddList" << std::endl;
    
    //Message stating what the expected and actual output
    //value are
    std::cout << "Expected value is \"" << expected  << "\""
    << " and output value is \"" << output << "\"" << std::endl;
    
    //If output is equal to expected then we have a successful
    //test
    if(output == expected){
        //Message for success
        std::cout << "Success!" << std::endl;
        //Set the success flag to true
        successFlag = true;
    }
    //The test failed
    else{
        //Message for test failure
        std::cout << "Test failed" << std::endl;
    }
    //Return success flag
    return successFlag;
    
}

int main(int argc, char** argv){
    
    //Testing AddLists
    //Flag for all tests succeeding
    bool totalSuccess = true;
    //Create all the variables for testing
    //LinkedList<int> intList1;
    //LinkedList<int> intList2;
    //LinkedList<int> resultList;
    std::string expected, output;
    std::ostringstream ostream;

    //Test 1
    //Arrange
    //intList1 will be 123
    LinkedList<int> intList1 = LinkedList<int>(3);
    //intList2 will be 456
    LinkedList<int> intList2 = LinkedList<int>(6);
    //Act
    intList1.Add(2);
    intList1.Add(1);
    intList2.Add(5);
    intList2.Add(4);
    LinkedList<int> resultList1 = 
        LinkedList<int>::AddList(intList1, intList2);

    expected = "9 -> 7 -> 5";
    ostream << resultList1;
    output = ostream.str();
    ostream.str("");
    //Assert
    totalSuccess &= AddListTestResults(output, expected);


    //Test2
    //Arrange
    //intList3 will be 500
    LinkedList<int> intList3 = LinkedList<int>(0);
    //intList4 will be 600
    LinkedList<int> intList4 = LinkedList<int>(0);
    //Act
    intList3.Add(0);
    intList3.Add(5);
    intList4.Add(0);
    intList4.Add(6);

    LinkedList<int> resultList2 = 
        LinkedList<int>::AddList(intList3, intList4);

    expected = "0 -> 0 -> 1 -> 1";
    ostream << resultList2;
    output = ostream.str();
    ostream.str("");
    //Assert
    totalSuccess &= AddListTestResults(output, expected);


    //Test3
    //Arrange
    //intList5 will be 2
    LinkedList<int> intList5 = LinkedList<int>(2);
    //intList6 will be 999
    LinkedList<int> intList6 = LinkedList<int>(9);
    //Act
    intList6.Add(9);
    intList6.Add(9);

    LinkedList<int> resultList3 = 
        LinkedList<int>::AddList(intList5, intList6);

    expected = "1 -> 0 -> 0 -> 1";
    ostream << resultList3;
    output = ostream.str();
    ostream.str("");
    //Assert
    totalSuccess &= AddListTestResults(output, expected);

    //Check if all tests passed
    if(totalSuccess){
        std::cout << "All tests passed successfuly" << std::endl;
    }
    else{
        std::cout << "Some tests have failed" << std::endl;
    }

}
