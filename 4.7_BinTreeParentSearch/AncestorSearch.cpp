/* AncestorSearch.cpp
 * This is a main program file for testing the ancestor
 * searching function in the BTree class. All it should
 * do is crate that BTree, add some nodes, call the
 * FindFirstCommonAncestor function, and verify it is
 * is correct.
 */

#include "TreeNode.h"
#include <iostream>

template <class T>
bool CommonAncestorTest(T expectedValue, TreeNode<T>* returnedNode,
                        bool expectedNull = false){
    //Make a return test success flag
    bool testSuccess = false;
    //State what the test is
    std::cout << "Testing the retrieval of a common ancestor" 
        << std::endl;
    //Test for null
    if(!returnedNode){
        //If it is null and that was expected
        if(expectedNull){
            std::cout << "No node was returned as expected"
                << std::endl;
            //The test succeeded
            testSuccess = true;
        }
        //If it was null and that is unexpected
        else{
            std::cout << "No node was returned indicating failure" 
                << std::endl;
        }
        return testSuccess;
    }
    //Test value of node
    T returnedValue = returnedNode->data;
    //Relies of type T having an == operatator defined
    if(expectedValue == returnedValue){
        //print success message
        std::cout << "Test Success!" << std::endl;
        testSuccess = true;
    }
    //Test failed
    else{
        //print test failure message
        std::cout << "Test failure" << std::endl;
    }
    return testSuccess;
}

int main(int argc, char** argv){
    //Testing the find common ancestor function    
    bool totalSuccess = true;

    //Test1
    //Arrange
    //Make a tree by creating a head
    TreeNode<int>* head = new TreeNode<int>();
    head->data = 4;
    //Act
    head->left = new TreeNode<int>();
    head->right = new TreeNode<int>();
    head->left->data = 10;
    head->right->data = -30;
    TreeNode<int>* ancestor = 
        head->FindFirstCommonAncestor(head->left,head->right);
    
    //Assert
    //Test if the node found is what we are looking for
    totalSuccess &= CommonAncestorTest<int>(4, ancestor);
    delete head;

    //Space between tests
    std::cout << std::endl;    

    //Test2
    //Arrange
    head = new TreeNode<int>();
    head->data = 10;
    //Act
    TreeNode<int>* node1 = new TreeNode<int>();
    node1->data = 20;
    head->left = node1;

    TreeNode<int>* node2 = new TreeNode<int>();
    node2->data = 50;
    head->right = node2;

    TreeNode<int>* node3 = new TreeNode<int>();
    node3->data = 30;
    head->left->left = node3;
    
    TreeNode<int>* node4 = new TreeNode<int>();
    node4->data = 700;
    head->left->left->left = node4;
    
    TreeNode<int>* node5 = new TreeNode<int>();
    node5->data = 100;
    head->left->right = node5;
   
    ancestor = head->FindFirstCommonAncestor(node4, node5);
    //Assert
    //Test if the node found is what we are looking for
    totalSuccess &= CommonAncestorTest<int>(20, ancestor);
    delete head;
   
    //Space between tests
    std::cout << std::endl;

    //Test3
    //Arrange
    TreeNode<char>* charHead = new TreeNode<char>();
    charHead->data = 'a';
    //Act
    TreeNode<char>* charNode1 = new TreeNode<char>();
    charNode1->data = 'f';
    charHead->left = charNode1;

    TreeNode<char>* charNode2 = new TreeNode<char>();
    charNode2->data = 'c';
    charHead->right = charNode2;
    
    TreeNode<char>* charNode3 = new TreeNode<char>();
    charNode3->data = 'm';
    charHead->left->left = charNode3;

    TreeNode<char>* charAncestor = charHead->FindFirstCommonAncestor
                                             (charNode2, charNode3);
    //Assert
    //Test if the node found is what we are looking for
    totalSuccess &= CommonAncestorTest<char>('a',  charAncestor);
    delete charHead;

    //Space between tests
    std::cout << std::endl;
    
    //Test4
    //Arrange
    charHead = new TreeNode<char>();
    charHead->data = 'q';
    //Act
    charNode1 = new TreeNode<char>();
    charNode1->data = 'z';
    charHead->left = charNode1;

    charNode2 = new TreeNode<char>();
    charNode2->data = 'a';
    charHead->right = charNode2;

    charNode3 = new TreeNode<char>();
    charNode3->data = 'l';
    charHead->left->left = charNode3;

    TreeNode<char>* charNode4 = new TreeNode<char>();
    charNode4->data = 'm';
    charHead->left->right = charNode4;
    
    TreeNode<char>* charNode5 = new TreeNode<char>();
    charNode5->data = 'n';
    charHead->right->left = charNode5;

    TreeNode<char>* charNode6 = nullptr;

    //This will be null
    charAncestor = charHead->FindFirstCommonAncestor
                    (charNode3, charNode6);


    //Test expects null
    totalSuccess &= CommonAncestorTest<char>('q', charAncestor, true);

    //See if all tests were successful or not
    if(totalSuccess){
        //print success message
        std::cout << "All tests passed!" << std::endl;
    }
    else{
        //print failure message
        std::cout << "Some tests have failed" << std::endl;
    }
}
