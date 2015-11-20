/* BSTreeDepth.cpp
 * Test the tree depth testing functionality of BSTree. The function
 * is supposed to return if the tree is balenced, if the max depth
 * never varies by more than 1.
 */


#include "BSTree.h"
#include <iostream>

//Simple function for printing the results of the test
bool depthTestResults(BSTree& tree, bool result, bool expected){
    //Make a flag for the test being successful or not
    bool testSuccessFlag = false;
    //print the tree
    std::cout << "For the tree" << std::endl;
    tree.PreOrderPrint();
    //state the conditions of the test
    std::cout << "The expected value is " << std::boolalpha << expected
        << std::endl;
    std::cout << "and the actual value is " << std::boolalpha << result
        << std::endl;
    //Set the flag if the expected == result
    if(expected == result){
        testSuccessFlag = true;
        //Print test success message
        std::cout << "Success!" << std::endl;
    }
    else{
        //Print test failure message
        std::cout << "Test failed" <<std::endl;
    }
    return testSuccessFlag;
    
    
}

int main(int argc, char** argv){

    //Start testing BSTree::BalanceTest
    bool result;
    bool expected;
    bool totalSuccess = true;

    //Test1
    //Arrange
    BSTree tree1 = BSTree();
    expected = true;
    //Act
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(7);
    result = tree1.BalanceTest();
    //Assert
    totalSuccess &= depthTestResults(tree1, result, expected);

    //Test2
    //Arrange
    BSTree tree2 = BSTree();
    expected = false;
    //Act
    tree2.Insert(5);
    tree2.Insert(10);
    tree2.Insert(7);
    tree2.Insert(8);
    tree2.Insert(9);
    tree2.Insert(2);
    result = tree2.BalanceTest();
    //Assert
    totalSuccess &= depthTestResults(tree2, result, expected);

    //Test3
    //Arrange
    BSTree tree3 = BSTree();
    expected = true;
    //Act
    tree3.Insert(10);
    tree3.Insert(5);
    tree3.Insert(3);
    tree3.Insert(7);
    tree3.Insert(15);
    tree3.Insert(12);
    tree3.Insert(17);
    result = tree3.BalanceTest();
    //Assert
    totalSuccess &= depthTestResults(tree3, result, expected);
    
    //Test4
    //Arrange
    BSTree tree4 = BSTree();
    expected = false;
    //Act
    tree4.Insert(5);
    tree4.Insert(3);
    tree4.Insert(7);
    tree4.Insert(8);
    tree4.Insert(10);
    result = tree4.BalanceTest();
    //Assert
    totalSuccess &= depthTestResults(tree4, result, expected);
    

    //Print meesage for all tests being successful
    if(totalSuccess){
        std::cout << "All tests passed!" << std::endl;
    }
    else{
        std::cout << "Some tests have failed" << std::endl;
    }   
}
