/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-bonus-problem/problem/check-for-balanced-tree
*/

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    int isBalanceRec(Node* root){
        if(!root) return 0;
        
        int lHeight = isBalanceRec(root->left);
        int rHeight = isBalanceRec(root->right);
        
        if(lHeight == -1 || rHeight == -1 || abs(lHeight - rHeight) > 1)
            return -1;
            
        return max(lHeight,rHeight)+1;
    }
    
  public:
    bool isBalanced(Node* root) {
        // code here
        return (isBalanceRec(root) > 0);
    }
};