/* BSTree.h
 * Define BSTree class.
 * Represents a binary search tree. A binary search tree is a tree
 * where each node has exactly two nodes a left and right. The left
 * node is less than the parent and the right node is more than the
 * parent.
 * A seperate class definition will be here for a tree node. It will
 * just contain an int(I am not making this a generic template) and
 * pointers to a left and right node
 * Author: Ryan Cori
 * Date: 11/5/15
 */

//File guards
#ifndef _BSTREE_
#define _BSTREE_

class TreeNode{
public:
    //Create a constructor that initializes data to 0 and pointers
    //to nullptr
    TreeNode(int inputData): data(inputData), leftNode(nullptr), 
                                rightNode(nullptr)
    {};
    int data;
    TreeNode* leftNode;
    TreeNode* rightNode;
};

class BSTree{
public:
    //Constructor to make a BSTree with no nodes
    BSTree();
    //Destructor to remove every node
    ~BSTree();
    //Insert a new node with data InputData
    void Insert(int inputData);
    //Search for a node with data searchData and return it
    TreeNode* Search(int searchData);
    //Do PreOrder traversal and print
    void PreOrderPrint();
    //Do InOrder traversal and print
    void InOrderPrint();
    //Return if the tree is balanced
    bool BalanceTest();
    //Do PostOrder traversal and print
    void PostOrderPrint();
    //Delete a particular node
    void DeleteNode(int inputData);
private:
    //Recursive function for the destructor
    void bst_destroy(TreeNode* node);
    //Recursive part of Insert function that searches for the
    //correct leaf node to insert inputData
    void insertRec(int inputData, TreeNode* node);
    //Recursive call for the search function to try to locate a node
    //If the node is found it will return that node
    TreeNode* searchRec(int inputData, TreeNode* node);
    //Recursive call for PreOrderPrint
    void preOrderPrintRec(TreeNode* node); 
    //Recursive call for InOrderPrint
    void inOrderPrintRec(TreeNode* node);
    //Recursive call for PostOrderPrint
    void postOrderPrintRec(TreeNode* node);
    //Recursive function to record the smallest and largest depth
    //of the tree.
    void branchDepthSearch(TreeNode* node, int curDepth, 
                                   int& smallestDepth,
                                   int& largestDepth);
    
    //Helper function that searches recursivly for the node to
    //delete by calling deleteNodeHelper on each child if possible
    void deleteNodeHelper(int nodeData, TreeNode* node,
                                            TreeNode* parent);
    //When deleting a node that has two children the next larger
    //Node the in the tree is removed from it's position and it's
    //replaces the value of the node being deleted. Returns the
    //value of that node after deleting it
    int deleteNodeLeftmost(TreeNode* node, TreeNode* parent);

 
    TreeNode* root;
};

#endif
