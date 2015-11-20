/* LinkedListNode.cpp
 * Implements the 3 class functions defined in LinkedListNode.h.
 * These functions are: Add, RemoveAt, and RemoveDuplicates I
 * may need to move Add to a different file to be included in
 * the header. This is because it is a template function for
 * now I will define it here. THe constructor is also defined
 * here.
 */

#include "LinkedListNode.h"
#include <iostream>

//Constructor
template <class T>
LinkedListNode<T>::LinkedListNode(T newData){
    //assign the passed in value to this node's
    //data field
    data = newData;
    //Right now this is a new list or the end of
    //the end of the tail of an existing list. In
    //either case there is no next node. Give it
    //nullptr
    next = nullptr;
}

//Desctructor
template <class T>
LinkedListNode<T>::~LinkedListNode(){
    //Do not destroy anything
}

//Create a new node with T data newData. Used by
//client to append to the tail of the list
template <class T>
void LinkedListNode<T>::Add(T newData){
    //First construct the new node
    LinkedListNode* newNode = new LinkedListNode(newData);
    //Now loop through the links of the list until
    //we hit the end, which will hav a nullptr as
    //a next node
    LinkedListNode* curNode = this;
    while(curNode->next != nullptr){
        //Move along to the next node
        curNode = curNode->next;
    }
    //Now curNode is the end-of-tail node. Set
    //it's nest to the new node that was made
    curNode->next = newNode;
}

//Deletes linked list node at supplies index. Returns
//if removal successful.
template <class T>
bool LinkedListNode<T>::RemoveAt(int indexAt){
    //Create a return value boolean
    bool retVal = false;
    //Verifry that more than one node exists. If not
    //return false
    if(!next){
        retVal = false;
        return retVal;
    }
    //The case for indexAt = 0 is handeled specially
    if(indexAt == 0){
        //We delete the first node, which is also
        //"this", so hold a new reference to it
        LinkedListNode* deleteNode = this;
        //Now set this equal to the next node.
        //this = deleteNode->next;
        //Delete deleteNode, which was "this"
        delete deleteNode;
        //Deletion successful
        retVal = true;
    }
    else{
        //Need reference to node previous to what we
        //want to delete after 1st node. Make two
        //pointers, a previous and current.
        LinkedListNode* prevNode = this;
        LinkedListNode* curNode = next;
        //Now iterate through up to the selected node.
        for(int i = 0; i <= indexAt; i++){
            //Return if curNode is null. That means we
            //reached the end of the list and did not
            //find the node. Index was too large
            if(!curNode){
                return retVal;
            }
            //advance both pointers
            prevNode = prevNode->next;
            curNode = curNode->next;
        }
        //We reached the node to delete
        //Remove it from the list.
        prevNode = curNode->next;
        //Delete the node object
        delete curNode;
        //Deletion was successful. Set the success flag
        retVal = true;
    }
    //Nothing left to do, return
    return retVal;
}

//This function is the goal of this exercise. Look for
//duplicate nodes and delete them. No temporary storage
//allowed
template <class T>
void LinkedListNode<T>::RemoveDuplicates(){
    //Start iteration over the list
    LinkedListNode* firstNodePtr = this;
    while(firstNodePtr != nullptr){
        //Start second iteration of the list after the
        //first node pointer.
        //We keep two pointers for this iteration because
        //in order to delete a node we need reference to
        //the node before it.
        //The node we are checking to possibly delete
        LinkedListNode* deleteCandidate = firstNodePtr->next;
        //The previous node
        LinkedListNode* prevNode = firstNodePtr;
        //Iteration loop
        while(deleteCandidate != nullptr){
            //Check if deleteCandidate is a duplicate of
            //firstNodePtr
            if(deleteCandidate->data == firstNodePtr->data){
                //Use prevNode to "skip over" the node we
                //are deleteing
                prevNode->next = prevNode->next->next;
                //Now do actual deleteion
                delete deleteCandidate;
                //We are done now, break from this loop
                break;
            }
            //Advance both pointers
            prevNode = prevNode->next;
            //deleteCandidate may have been deleted so use
            //prevNode to advance
            deleteCandidate = prevNode->next;
        }
        //Advance the first/outer loop iteration through
        //the list
        firstNodePtr = firstNodePtr->next;
    }
}



template class LinkedListNode<int>;
