/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/check-for-bst
*/

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        Node* curr=root;
        Node* prev=nullptr;
        int prevVal=INT_MIN;
        while(curr){
            if(curr->left==nullptr){
                if(curr->data<=prevVal)
                    return false;
                prevVal=curr->data;
                curr=curr->right;
            }
            else{
                prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    if(curr->data<=prevVal){
                        return false;
                    }
                    prevVal=curr->data;
                    curr=curr->right;
                }
            }
        }
        return true;
    }
};