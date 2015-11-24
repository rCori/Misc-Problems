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
    //COnstructor just sets everything to nullptr
    TreeNode(){
        left = nullptr;
        right = nullptr;
    }
    ~TreeNode(){
        if(right){
            delete right;
        }
        if(left){
            delete left;
        }
    }
    //Search for specific data and return the node that contains it
    //If it does not exists returns nullptr
    TreeNode* Search(T searchData){
        TreeNode* searchNode = nullptr;
        //First check if this node is this node you are searching
        //for
        if(data == searchData){
            searchNode = this;
        }
        //Search all children possible
        TreeNode* leftNode = nullptr;
        TreeNode* rightNode = nullptr;
        if(left){
            leftNode = left->Search(searchData);
        }
        if(right){
            rightNode = right->Search(searchData);
        }       
        
        //If either child contained the node we are searching for
        //then return it.
        if(rightNode)
        {
            searchNode = rightNode;
        }
        if(leftNode){
            searchNode = leftNode;
        }

        //Return whatever we managed to find
        return searchNode;
    }
    //Search for the first common ancestor tree node of two nodes
    //If it does not exist it returns nullptr
    TreeNode* FindFirstCommonAncestor(TreeNode* a, TreeNode* b){
        //Create a node to return
        TreeNode* returnNode = nullptr;
        //If either of the nodes are null, then obviously
        //they have no common ancestor
        if(!a || !b){
            //Is null
            return returnNode;
        }
        //call the recusrive function to start searching
        returnNode = findAncestorRec(a, b);
        return returnNode;
    }
private:
    //Helper function for FindFirstCommonAncestor
    //Searches for TreeNode's a and b. It it determines that
    //this is the first common ancestor it will return it.
    //If not but it has more information to continue searching
    //deaper in the tree, it will. If it is out of searching options
    //it will just return nullptr
    TreeNode* findAncestorRec(TreeNode* a, TreeNode* b){
        //If node a is actually the node we are searching right now
        //it could be the common ancestor if b is it's child
        if(this == a){
            if(Search(b->data)){
                return a;
            }
        }
        //Same check only for node b
        if(this == b){
            if(Search(a->data)){
                return b;
            }
        }

        //If we are not searching a or b, the only way this could
        //be the ancestor node still is if a exists on one child
        //subtree of this and b is on the other child subtree.
        bool aOnLeft = false;
        bool aOnRight = false;
        bool bOnLeft = false;
        bool bOnRight = false;
        //See if a or b are on the left subtree if it exists
        if(left){
            aOnLeft = left->Search(a->data);
            bOnLeft = left->Search(b->data);
        }
        if(right){
            aOnRight = right->Search(a->data);
            bOnRight = right->Search(b->data);
        }
        
        //If we found a on one side and b on the other, then this is
        //the ancestor we are looking for.
        if((aOnRight && bOnLeft) || (bOnRight && aOnLeft)){
            return this;
        }
        //if we did not find the two nodes split but found them
        //on one side, we continue searching down that side if possible
        else if(right && aOnRight && bOnRight){
            return right->findAncestorRec(a,b);
        }
        else if(left && aOnLeft && bOnLeft){
            return left->findAncestorRec(a,b);
        }
        return nullptr;
    }
};


