/* BSTree.cpp
 * Implementation file for BSTree class
 * All functions for the BSTree class will be implemented in here
 * Author: Ryan Cori
 * Date: 11/9/15
 */

#include "BSTree.h"

#include <iostream>
#include <limits>

//Constructor, all it should do set the root to nullptr
BSTree::BSTree(): root(nullptr){
}


//Delete all nodes in the tree
BSTree::~BSTree(){
    bst_destroy(root);
}

//Insert node with data inputData
void BSTree::Insert(int inputData){
    //If the root is null, then the new node is the root
    if(!root){
        //Create the new node
        //Set node's data to inputData
        TreeNode* node = new TreeNode(inputData);
        //Both chidlren are null
        node->leftNode = nullptr;
        node->rightNode = nullptr;
        root = node;
        //Return to avoid the recursive call
        return;
    }
    insertRec(inputData, root);
    
}

//Search for a node with 
TreeNode* BSTree::Search(int inputData){
    TreeNode* node = searchRec(inputData, root);
    return node;
}

//Do a PreOrder print of the tree
void BSTree::PreOrderPrint(){
    //Call the private recursive function
    preOrderPrintRec(root);
}

//InOrder print of the tree
void BSTree::InOrderPrint(){
    //Call the privte recursive function
    inOrderPrintRec(root);
}

//PostOrder print of the tree
void BSTree::PostOrderPrint(){
    //Call the pricate recursive function
    postOrderPrintRec(root);
}

//Test if the tree is balanced or not
bool BSTree::BalanceTest(){
    bool BalancedFlag = false;
    //Create return argument ints
    int smallestDepth = std::numeric_limits<int>::max();
    int largestDepth = std::numeric_limits<int>::min();
    branchDepthSearch(root, 0, smallestDepth, largestDepth);

    //Use the int references of smallesDepth and largestDepth
    //to determine if depths are within threshold to call the
    //tree balances
    int depthDifferences = largestDepth - smallestDepth;
    if(depthDifferences <=1 && depthDifferences >= -1){
        BalancedFlag = true;
    }
    return BalancedFlag;
}

//Look for a node with data inputData and delete it
void BSTree::DeleteNode(int inputData){
    //Call the recursive helper on the root to start the 
    //deletion process
    deleteNodeHelper(inputData, root, nullptr);
}

//Recursive function to destroy 
void BSTree::bst_destroy(TreeNode* node){
    //Try to delete left node
    if(node->leftNode){
        //Call the destroy function
        bst_destroy(node->leftNode);
    }
    //Try to delete right node
    if(node->rightNode){
        //Call the destroy function
        bst_destroy(node->rightNode);
    }
    //Now delete this node after any children have been deleted
    delete node;
    
}

//Recursive function to search for the right leaf to insert
//a new node with data inputData
void BSTree::insertRec(int inputData, TreeNode* node){
    //Find what child inputData would be
    //If inputData is less than the data in the node then it
    //is a left child
    if(inputData < node->data){
        //If node's left child is null then we create the new
        //node as the left child
        if(!node->leftNode){
            //Create the new node and insert it
            TreeNode* newNode = new TreeNode(inputData);
            //Assign it to the new node
            node->leftNode = newNode;
        }
        //Otherwise we recurse on that left child
        else{
            //Call recursivley on left child
            insertRec(inputData, node->leftNode);
        }
    }
    //If input data is greater than or equal to node data then
    //it is a right child
    else{
        //If node's right child is null then we create the new
        //node as the right child
        if(!node->rightNode){
            //Create the new node and insert it
            TreeNode* newNode = new TreeNode(inputData);
            //Assign it to the new node
            node->rightNode = newNode;
        }
        else{
            //Call recursivley on right child
            insertRec(inputData, node->rightNode);
        }
    }
}

//Recursive function for searching for a node with data inputData
//If found then return in otherwise recurse into both children
TreeNode* BSTree::searchRec(int inputData, TreeNode* node){
    
    //Declare a node to return
    TreeNode* curNode = nullptr;

    //If this node is null, then our search has failed.
    //Return a nullptr early
    if(!node){
        return curNode;
    }

    //If the data we are searching for is less than the data in the node
    //we need to search the left child
    if(inputData < node->data){
        //Search recursivley on left child
        curNode = searchRec(inputData, node->leftNode);
    }
    //If the data we are searching for is greater than the data the
    //node we need to search the right child
    else if (inputData > node->data){
        curNode = searchRec(inputData, node->rightNode);
    }
    //If the the data we are searching for is equal to what is in the
    //node, we found the node we are looking for
    else{
        //Assign curNode to the node we are searching for
        curNode = node;
    }
    //Return the curNode we have now
    return curNode;
}


//Recursive function for PreOrder print
void BSTree::preOrderPrintRec(TreeNode* node){
    //First print
    std::cout << node->data << std::endl;
    //Recursive call on left child
    if(node->leftNode){
        preOrderPrintRec(node->leftNode);
    }
    //Recursive call on right child
    if(node->rightNode){
        preOrderPrintRec(node->rightNode);
    }
}


//Recursive function for InOrder print 
void BSTree::inOrderPrintRec(TreeNode* node){
    //Recursive call on left child
    if(node->leftNode){
        inOrderPrintRec(node->leftNode);
    } 
    //Then print
    std::cout << node->data << std::endl;
    //Recursive call on right child
    if(node->rightNode){
        inOrderPrintRec(node->rightNode);
    }
}


//Recursive function for PostOrder print
void BSTree::postOrderPrintRec(TreeNode* node){
    //Recursive call on left child
    if(node->leftNode){
        postOrderPrintRec(node->leftNode);
    } 
    //Recursive call on right child
    if(node->rightNode){
        postOrderPrintRec(node->rightNode);
    }
    //Last print
    std::cout << node->data << std::endl;
}

//Recursive call that stores the largest and smallest leaf
//node depths found so far
void BSTree::branchDepthSearch(TreeNode* node, int curDepth, 
                       int& smallestDepth,
                       int& largestDepth){
    //First add one to depth
    curDepth++;
    //Check if this is a leaf node
    if(!node->leftNode && !node->rightNode){
    //If it is, see if curDepth is smaller than the current
    //smallest or larger than the current largest depth and
    //if so replace them with the current depth
        if(curDepth < smallestDepth){
            smallestDepth = curDepth;
        }
        if(curDepth > largestDepth){
            largestDepth = curDepth;
        }
    }
    //If this is not a leaf node with no children, check what
    //children are present and recurisve call on as many as
    //possible
    else{
        //check left node
        if(node->leftNode){
            //Recursive call
            branchDepthSearch(node->leftNode, curDepth,
                              smallestDepth, largestDepth);
        }
        //check right node
        if(node->rightNode){
            //Recursive call
            branchDepthSearch(node->rightNode, curDepth,
                              smallestDepth, largestDepth);
        }
    }
    
}
//Recusive helper function for deleting a node
void BSTree::deleteNodeHelper(int nodeData, TreeNode* node,
                                TreeNode* parent){
    //Check if this is the node we want to delete
    if(nodeData != node->data){
        //This is not what we want to delete. Make recursive
        //calls to as many children as possible
        //Try left child
        if(node->leftNode){
            deleteNodeHelper(nodeData, node->leftNode, node);
        }
        //Try right child
        if(node->rightNode){
            deleteNodeHelper(nodeData, node->rightNode, node);
        }
    }
    //This is the node we want to delete so delete it
    else{
        TreeNode* left = node->leftNode;
        TreeNode* right = node->rightNode;
        //If this node is missing at least one child
        if(!left || !right){
            //Before deleting node we must fix the parent's child
            if(parent){
                //Find what which child this node is to parent
                //Left == 0, Right == 0
                int leftOrRight = 0;
                if(parent->rightNode == node){
                    leftOrRight = 1;
                }
                if(leftOrRight == 0){
                    //if the node had a left child, set it to the
                    //parent's new child replacement
                    if(left){
                        parent->leftNode = left;
                    }
                    //if the node had a right child, set it to the
                    //parent's new child replacement
                    else if(right){
                        parent->leftNode = right;
                    } 
                    //Node had no children, so just fill the parent's
                    //child with nullptr
                    else{
                        parent->leftNode = nullptr;
                    }
                }
                else{
                    //if the node had a left child, set it to the
                    //parent's new child replacement
                    if(left){
                        parent->rightNode = left;
                    }
                    //if the node had a right child, set it to the
                    //parent's new child replacement
                    else if(right){
                        parent->rightNode = right;
                    } 
                    //Node had no children, so just fill the parent's
                    //child with nullptr
                    else{
                        parent->rightNode = nullptr;
                    }
                }
            }
            //Finally we can delete the node
            delete node;
        }
        //if this node has both children
        else{
            //We will get a new value for node instead of deleting
            //it. In the process the node that previously had that
            //value will get deleted
            int newData = deleteNodeLeftmost(node->rightNode, node);
            node->data = newData;
        }
    } 
}

//Recursive helper function for deleting a node when it has
//two children. In that case this function will find the next
//largest node to what is being deleted, return it's node
//value and delete it
int BSTree::deleteNodeLeftmost(TreeNode* node, TreeNode* parent){
    //Make return int value
    int returnInt = 0;
    //If there is another left node
    if(node->leftNode){
        returnInt = deleteNodeLeftmost(node->leftNode, node);
    }
    //This is the leftmost node and the next largest from what
    //we are trying to delete
    else{
        //Get the node value
        returnInt = node->data;
        //Now we delete this node. Use deleteNodeHelper because
        //It could have right children still
        deleteNodeHelper(node->data, node, parent);
    }
    return returnInt;
}
