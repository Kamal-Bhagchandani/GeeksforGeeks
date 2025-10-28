/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-bonus-problem/problem/symmetric-tree
*/

/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  private:
    bool isMirror(Node* leftSub, Node* rightSub){
        if(!leftSub && !rightSub)
            return true;
            
        if(!leftSub || !rightSub || leftSub->data!=rightSub->data)
            return false;
            
        return isMirror(leftSub->left, rightSub->right) && 
               isMirror(leftSub->right, rightSub->left);
    }
  public:
    bool isSymmetric(Node* root) {
        // Code here
        if (!root)
            return true;
        
        return isMirror(root->left,root->right);
    }
};