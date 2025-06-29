/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/find-a-pair-with-given-target-in-bst
*/

/*
Node is as follows
class Node {
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
    void findTargetRec(Node* root,vector<int>& arr){
        if(!root)
            return;
            
        findTargetRec(root->left,arr);
        arr.push_back(root->data);
        findTargetRec(root->right,arr);
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int> arr;
        findTargetRec(root,arr);
        int l=0,r=arr.size()-1;
        while(l<r){
            int sum=arr[l]+arr[r];
            if(sum==target)
                return true;
            else if(sum<target)
                l++;
            else
                r--;
        }
        return false;
    }
};