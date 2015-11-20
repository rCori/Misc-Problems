/* LinkedListNode.h
 * A single node of a singly linked list that will contain
 * generic data and a pointer to a next node. The Next node
 * will be initialized to nullptr and remain nullptr until
 * the next node is added to the list. The node at the very
 * end of the tail wil have a nullptr for a next node.
 * LinkdedListNode class will have 3 class functions, Add
 * RemoveAt, and RemoveDuplicates. This is not a complete
 * implementation of a singly linked list, but this will
 * be sufficient for implementing the RemoveDuplicates
 * function, which is the interview style questions being
 * asked
 * Date: 11/1/15  
 * Author: Ryan
 */

#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <iostream>

template <class T>
class LinkedListNode{
public:
    //Constructor can be used by client to make a new list
    //or by the Add function to make a node to add to an
    //existing list.
    explicit LinkedListNode(T newData);
    //T and next will not be deletes. This desctructor
    //will do very little
    ~LinkedListNode();
    //For adding a new node to the linked list at the end
    //of the tail. Client cannot add a node they created
    //themselves intentionally. Add constructs the new
    //LinkedListNode itself, not the cliean
    void Add(T newData);
    //Using a double-loop method, seeks out nodes containing
    //duplicate data to nodes earlier in the list. These
    //duplicates are the cleanly deleted.
    void RemoveDuplicates();
    //Follows through specific number of links and cleanly
    //deletes the node there. If successful returns true
    //and if the selected index was to large or any other
    //failure occured, returned false
    bool RemoveAt(int indexAt);
    //Overload this operator in order to test the contents
    //of the list after operations are performed and functions
    //are called
    template <class NType>
    friend std::ostream& operator<<(std::ostream& os, 
                                      const LinkedListNode<NType>& node){
        
        //make a non-const node to iterate through
        LinkedListNode* curNode = new LinkedListNode(node);
        //while the node is not null
        while(curNode){
            os << curNode->data;
            //add an arrow to the end unless it is the last node
            //check if it is the last node
            if(curNode->next){
                //Add the arrow
                os << " -> ";
            }
            curNode = curNode->next;
        }
        //clean up the pointer we made
        delete curNode;
        //Finally return the stream
        return os;
    }
private:
    //The data stored at this specific linked list node
    T data;
    //A pointer to the next node after this one
    LinkedListNode* next;
}; 


#endif
