/* MinStack.h
 * Keep track of the minimum element pushed onto a stack. Min function
 * returns the minimum element on the stack currently. Implemented
 * using two stacks, a main stack and a min stack.
 * Author: Ryan Cori
 * Date: 11/5/15
 */

//File guards
#ifndef _MIN_STACK_
#define _MIN_STACK_


#include <iostream>
#include <sstream>

/* I can't acutally make an enum becuase this is a template class
 * so I will pretend here
 * enum StackSelect{
 *     MAIN = 0,
 *     MIN = 1
 * };
 */

template <class T>
class MinStack{
private:
    //Define the node class
    class StackNode{
    public:
        T element;
        StackNode* next;
        StackNode(){
            next = nullptr;
        } 
    };
    //Helper functions to be called by the two top StackNode*s for
    //pushing and popping
    void stackPush(/*StackSelect*/int stackSelect, T nodeElement);
    T stackPop(/*StackSelect*/int stackSelect);

    //Helper for printing a stack from the top of topNode
    static std::string stackPrint(StackNode* stackSelect);    

    //The two StackNode*s that will be the tops of the two stacks
    //The main stack
    StackNode* top;
    //The minimum stack
    StackNode* minTop;
public:
    //Standard constructor declaring 
    MinStack();
    //Public interface to push onto the Stack. Both stacks
    //will be pushed to if the element being pushed is less
    //than or equal to the top of the minStack.
    void Push(T nodeElement);
    //Public interface to pop from the stack. If both stacks
    //have the same top, both will be popped
    T Pop();
    //Return the current smalles item on the stack. This
    //is thetop of the minStack
    T Min();
    //Overload this operator in order to test the contents
    //of the stack.
    friend std::ostream& operator<<(std::ostream& os,
                                    const MinStack& node){
        
        //Print that this is the main stack
        os << "Main Stack" << std::endl;
        //print the main stack
        os << MinStack::stackPrint(node.top);
        //Space after the main stack printout
        os << std::endl;


        //Start printing the min stack
        //print that this is the min stack
        os << "Minimum Stack" << std::endl;
        //print the min stack
        os << MinStack::stackPrint(node.minTop);
        //Space after the min stack printout
        return os;
    }
};



#include "MinStack.cpp"

#endif
