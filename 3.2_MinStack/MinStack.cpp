/* MinStack.cpp
 * Implementation of the MinStack as defined in the file MinStack.h
 * 2 private: stackPop, stackPush
 * 3 public: Pop, Push, Min
 * Author: Ryan Cori
 * Date: 11/5/15
 */

#ifdef _MIN_STACK_ 


#include "MinStack.h"


#include <iostream>
#include <sstream>

//Constructor that initializes all pointers to nullptr
template <class T>
MinStack<T>::MinStack(){
    //Top of the main stack
    top = nullptr; 
    //Top of the min stack
    minTop = nullptr;
}

//Helper function to pop from a stack given the top of 
//the stack
template <class T>
T MinStack<T>::stackPop(/*StackSelect*/int stackSelect){
    //Make a curNode to be a top node of the stack we are popping from
    StackNode* topNode;
    //Assign curNode to the correct node
    switch(stackSelect){
    case /*MAIN*/0:
        topNode = top; 
        break;
    case /*MIN*/1: 
        topNode = minTop;
        break;
    default:
        break;
    }
    //Save the top element
    T returnElement = topNode->element;
    //Save the top node itself for deletion
    StackNode* oldTop = topNode;
    //advance topNode down the stack

    //Assign curNode to the correct node
    switch(stackSelect){
    case /*MAIN*/0:
        top = topNode->next; 
        break;
    case /*MIN*/1: 
        minTop = topNode->next;
        break;
    default:
        break;
    }
    //delete the old top node now that it is gone
    delete oldTop;
    return returnElement;
    
}

//Helper functions to push onto a stack given the top
//of the stack
template <class T>
void MinStack<T>::stackPush(/*StackSelect*/int stackSelect, T nodeElement){
    //Make a reference to a top node
    StackNode* topNode;    
    //Assign curNode to the correct node based on the stack select
    //enum. Read top of MinStack.h for details
    switch(stackSelect){
    case /*MAIN*/0:
        topNode = top; 
        break;
    case /*MIN*/1: 
        topNode = minTop;
        break;
    default:
        break;
    }
    //First make a new StackNode*
    StackNode* newNode = new StackNode();
    //Set it's element to the argument nodeElement and
    //next to nullptr
    newNode->element = nodeElement;
    //The new node is pushed on top so current top is
    //it's next
    newNode->next = topNode;
    //the newNode is now top
    topNode = newNode;
    
    //Reassign the correct top node
    switch(stackSelect){
    case /*MAIN*/0:
        top = newNode; 
        break;
    case /*MIN*/1: 
        minTop = newNode;
        break;
    default:
        break;
    }
}

//Helper for printing used by the operator<< overload
template <class T>
std::string MinStack<T>::stackPrint(StackNode* stackSelect){ 
    //Make a node to iterate from the top of the stack with
    StackNode* curNode = stackSelect;
    //Create an outstream to pipe all output too until return
    std::ostringstream os;
    //Iterate through the stack
    while(curNode){
        //print the element
        os << curNode->element;
        //advance the pointer
        curNode = curNode->next;
        //if the curNode isn't null now(the last node wasn't the
        //end of the stack) print an arrow
        if(curNode){
            //Print arrow
            os << " -> ";
        } 
    }
    //Return the string for of the string stream
    return os.str();
}

//Public interface for popping. Uses the helper pop to
//to possibly pop from both stacks if they have the
//same element
template <class T>
T MinStack<T>::Pop(){
    //If the main or min stack is empty then return early
    if(!top || !minTop){
        T returnElement = 0;
        return returnElement;
    }
    //Check if the two stack have the same top element
    //the same top element.
    if(top->element == minTop->element){
        //Pop from minStack
        stackPop(1);
    }
    //Pop from the main stack
    T mainElement = stackPop(0);
    //Return what popped off
    return mainElement;
} 

//Public interface for pushing onto a stack. Pushed onto
//the min stack as well if the pushed element is less than
//or equal to the current top of the minStack
template <class T>
void MinStack<T>::Push(T nodeElement){
    //Check if elementData is less than or equal to the
    //current min. If so then it gets pushed to the min 
    //stack
    if(!minTop || nodeElement <= minTop->element){
        stackPush(1, nodeElement);
    }
    //Push to the main stack
    stackPush(0, nodeElement);
}

//Peek at the top of the min stack. That will be
//the current smalled thing on the stack
template <class T>
T MinStack<T>::Min(){
    //return the min top element. The 
    return minTop->element;
}


#endif

