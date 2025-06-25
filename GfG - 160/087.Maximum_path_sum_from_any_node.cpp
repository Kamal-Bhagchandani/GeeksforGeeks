/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/maximum-path-sum-from-any-node
*/

// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return maximum path sum from any node in a tree.
    int findMaxSumRec(Node* root,int &res){
        if(!root)
            return 0;
            
        int l=max(0,findMaxSumRec(root->left,res));
        int r=max(0,findMaxSumRec(root->right,res));
        res=max(res,l+r+root->data);
        
        return max(l,r)+root->data;
    }
    int findMaxSum(Node *root) {
        // code here
        int res=root->data;
        findMaxSumRec(root,res);
        
        return res;
    }
};