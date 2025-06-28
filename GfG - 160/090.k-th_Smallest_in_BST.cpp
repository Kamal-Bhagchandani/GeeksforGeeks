/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/find-k-th-smallest-element-in-bst
*/

/*Complete the function below

struct Node {
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
    // Return the Kth smallest element in the given BST
    int count=0,res=-1;
    
    void kthSmallestRec(Node *root, int k) {
        // add code here.
        if(root==nullptr || count>k)
            return;
        kthSmallestRec(root->left,k);
        count++;
        if(count==k)
            res = root->data;
        kthSmallestRec(root->right,k);
    }
    int kthSmallest(Node *root, int k) {
        // add code here.
        count=0;
        res=-1;
        kthSmallestRec(root,k);
        return res;
    }
};