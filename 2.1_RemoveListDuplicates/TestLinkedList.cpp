/* TestLinkedList.cpp
 * A program for testing the functionality of LinkedListNode.
 * Will not test the RemoveDuplicates function. That will
 * happen in RemoveDuplicates.cpp. This will only test
 * construction, Add, and RemoveAt
 * Date: 11/1/15
 * Author: Ryan Cori 
 */

#include "LinkedListNode.h"
#include <iostream>
#include <string>


//Simple function used to test the string output of
//the list
template <class T>
void TestList(std::string expected, LinkedListNode<T>* node){
    //State the expected value
    std::cout << "After some operations we expect the output of "
                 "the linked list to be:" << std::endl;
    std::cout << expected << std::endl;

}

using namespace std;

int main(int argc, char** argv){
    
    //Testing Add
    //Create list variable for tests
    LinkedListNode<int>* node;
    std::string expected, output;
    //Testing add
    //Test 1
    //Arrange
    node = new LinkedListNode<int>(1);
    //Act
    //Assert
    //now add duplicates
    node->Add(2);
    node->Add(3);
    node->Add(4);
    node->Add(2);
    node->Add(4);
    //Now look at it again
    std::cout << *node << std::endl;
    //Remove duplicates
    node->RemoveDuplicates();
    //print results
    std::cout << *node << std::endl;
}
