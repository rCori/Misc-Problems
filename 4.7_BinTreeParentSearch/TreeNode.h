/* TreeNode.h
 * Implementation of a binary tree node for solving question 4.7
 * of Cracking the Coding Interview.
 * This is not a binary search tree, meaning it has no sequential
 * ordering. As such it will have no specific Add function.
 * The user will have to make a new TreeNode themselves and
 * set it to a child of an existing node in the tree.
 * Since there is no ordering involved, it is easy enough to make
 * the tree data type a templated type. That is why there is no
 * class implementation file TreeNode.cpp
 * Author: Ryan Cori
 * Date: 11/20/15
 */

template <class T>
class TreeNode{
public:
    //Data can be any type, it does not matter
    T data;
    //Left child
    TreeNode* left;
    //Right Child
    TreeNode* right;
    //Search for specific data and return the node that contains it
    //If it does not exists returns nullptr
    TreeNode* Search(T searchData){
        return nullptr;   
    }
    //Search for the first common ancestor tree node of two nodes
    //If it does not exist it returns nullptr
    TreeNode* FindFirstCommonAncestor(TreeNode* a, TreeNode* b){
        return nullptr;
    }
private:
    //Helper function for FindFirstCommonAncestor
    //Searches for TreeNode's a and b. It it determines that
    //this is the first common ancestor it will return it.
    //If not but it has more information to continue searching
    //deaper in the tree, it will. If it is out of searching options
    //it will just return nullptr
    TreeNode* findAncestorRec(TreeNode* a, TreeNode* b){
        return nullptr;
    }
};


