/* LinkedList.h
 * Doubley Linked list implementation that is generic but contains
 * static functions for adding two lists of ints together that are
 * not. A ListNode class will be kept here but privatly in the order
 * to keep it's details hidden.
 * LinkedList class contains a public contructor plus the public
 * member functions Add, GetAt, AddToStart, and a static AddIntLists. 
 * Private members are the function addIntListRecursive which is a
 * helper for AddInsLists and a private field ListNode* head.
 * The operator<< will be defined as a friend of the class for
 * printing the contents of the list.
 * The main function for the purpose of this exercise is AddIntLists.
 * Every other function will be tested in a TesList program while that
 * one will have a seperate AddList program for testing usage.
 * Since this class is generic, it's definition and implementation
 * will be in this file. No .cpp for this class will be made
 * Author: Ryan Cori
 * Date: 11/4/15
 */

//Header guards
#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <iostream>
#include <sstream>
#include <stdexcept>

template <class T>
class LinkedList{
private:
    class ListNode{
    public:
        //Data for the node
        T data;
        //doubley linked list so we need both a previous and a
        //next node
        ListNode* next;
        ListNode* prev;
    };
public:
    //standard constructor. Sets head to null because there are no
    //nodes
    LinkedList<T>(){
        head = nullptr;
    }
    
    //Constructor that assures at least the head node exists
    LinkedList<T>(T newData){
        //Create a new node that becomes the head of the list
        //since it is the only node
        ListNode* node = new ListNode();
        //Set parameter T data as the data for the new node
        node->data = newData;
        //Set both links for the node as nullptr because its
        //the solitary node for now
        node->prev = nullptr;
        node->next = nullptr;
        //Head of the list is the new node
        head = node;
        
    }
       
    //Destructor will start at the head and delete every node
    //until the end
    ~LinkedList<T>(){
        //Get a node to iterate from the head with
        ListNode* curNode = head;
        //Loop until we hit the end of the list when the next
        //node is null
        while(curNode){
            //Make pointer to next node now
            ListNode* nextNode = curNode->next;
            //delete the current node
            delete curNode;
            //set curNode to the next node;
            curNode = nextNode;
        }
    } 

    //Traditional linked list add. Adds new data to a new node 
    //at the end of the list
    void Add(T newData){
        //First construct a new node
        ListNode* newNode = new ListNode();
        //Assign it's data to newData
        newNode->data = newData;
        //Now loop through the links of the list unstil we reach
        //the end of the list which will have a nullptr for next.
        //First get a node to iterate with that starts at the
        //head of the list
        ListNode* curNode = head;
        //Now iterate
        while(curNode->next != nullptr){
            curNode = curNode->next;
        }
        //Now curNode is the very last node. Now we can append
        //the new node to the end. It's prev will be the former
        //lastnode, which is curNode right now
        curNode->next = newNode;
        newNode->prev = curNode;
        //We need to set the next of curNode to nullptr because
        //it is the new end of the list
        newNode->next = nullptr;
    }

    
    //A function for getting data at a specific index in the
    //linked list
    //throws and catches a logic error if argument index is
    //out of bounds
    T GetAt(int indexAt){
        //First check that index at is not less than 0
        try{
            if(indexAt < 0){
                throw std::invalid_argument("index accessed in"
                    "LinkedList less than 0");
            }
        }
        catch(std::invalid_argument& e){
            std::cout << e.what() << std::endl;
            T blankData = head->data;
            return blankData;
        }
        //Now we can iterate over the list indexAt times.
        //Make a T type to assign the selected node's data
        T selectedData;
        //Now iterate. Iteration may need to throw an
        //error if we run past bounds.
        ListNode* curNode = head;
        try{
            for(int i=0; i<indexAt; i++){
                curNode = curNode->next;
                //If curNode is now null we have marches off the
                //end of the list
                if(!curNode){
                    throw std::invalid_argument("index"
                        " accessor in LinkedList Out of Bounds");
                }
            }
        }
        catch(std::invalid_argument& e){
            std::cout << e.what() << std::endl;
            selectedData = head->data;
            return selectedData;
        }
        //After the loop curNode is the node that was selected
        selectedData = curNode->data;
        //Return selected data
        return selectedData;
    }


    //Static function. Only for LinkedList<int>
    //Add two LinkedList<int>s where each link is a digit in
    //reverse order
    //Example 2->9->3 is 392
    //Returns a LinkedList<int> in the same backwards digit
    //format
    static LinkedList<int> AddList(LinkedList<int> list1,
                                   LinkedList<int> list2){
        //Call the recursive version of the function that
        //actually does the work
        ListNode* node = addListRecursive(list1.head,
                                          list2.head,
                                          0);
        //Now use the node from the recursive call to 
        //construct a new list
        LinkedList<int> returnList = LinkedList<int>();
        returnList.head = node;

        return returnList; 
    }
         
   
    //Overload this operator in order to test the contents
    //of the list after operations are performed and functions
    //are called
    //The operator is not a template, it just takes a template
    //class as an argument. We want a copy of this operator overload
    //for each template class created.
    //It still needs to be a friend of the class to access class
    //members
    friend std::ostream& operator<<(std::ostream& os,
                                    const LinkedList& node)
    {
        //Get reference to the head of the LinkedList to
        //iterate through
        ListNode* curNode = node.head;
        //while the node is not null
        while(curNode){
            os << curNode->data;
            //Add an arrow to the end unless it is the
            //last node. Check if it is the last node.
            if(curNode->next){
                os << " -> ";
            }
            curNode = curNode->next;
        }
        //Return the stream object
        return os;
    }

private:
    ListNode* head;
    //The recursive function that does all of the work for the
    //public static function AddList. This is also static.
    //Adds teh int data of the two nodes plus the carry int
    //It makes a new node from that. Then it calls itself and
    //the return value becomes the next node for the newly created
    //one. Previous for the return node is the new node.
    //Then return the new node
    static ListNode/*<int>*/* addListRecursive(
                                ListNode/*<int>*/* node1,
                                ListNode/*<int>*/* node2,
                                int carry){
        //Return a nullptr early if both nodes are null
        //and carry is 0
        if(!node1 && !node2 && carry == 0){
            return nullptr;
        }
        //Make the new ListNode
        ListNode* newNode = new ListNode();
        //Now assign the node's data
        //Get the data for the new node
        int newNodeData = 0;
        //Add node1 and node2 data if they exist
        if(node1){
            newNodeData += node1->data;
        }

        if(node2){
            newNodeData += node2->data;
        }
        //Add the carry
        newNodeData+=carry;
        //Assign the data of newNode to newNodeData mod 10
        //mod 10 accounts for carrying the 1 if it is > 10
        newNode->data = newNodeData%10;
        //Calculate the carry. It is 1 if the current digits
        //add to 10 or greater and 0 otherwise
        int nextCarry = 0;
        if(newNodeData >= 10){
            nextCarry = 1;
        }
        //Make recursive call to get next for the new node
        //If both of the current nodes null and the carry
        //is 0 then this is the end and a nullptr should be
        // next and the recusive call doesn't happen
        ListNode* returnNode = nullptr;
            
        //Avoid nullptrs and specify what ListNode<int>*s
        //are being passed in
        ListNode* nextNode1 = nullptr;
        ListNode* nextNode2 = nullptr;
        if(node1){
            nextNode1 = node1->next;
        }
        if(node2){
            nextNode2 = node2->next;
        }
        //Now recursive call
        returnNode = addListRecursive(nextNode1, nextNode2,
                                      nextCarry);

        newNode->next = returnNode;
        //only set prev if returnNode isn't acutally the end
        //nullptr
        if(returnNode)
        {
            returnNode->prev = newNode;
        }
        //Now return returnNode
        return newNode;
    }
};

//#include "LinkedListFriends.cpp"

#endif
