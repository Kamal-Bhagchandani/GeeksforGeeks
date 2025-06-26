/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/k-sum-paths
*/

/*
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
    int sumKRec(Node* root,int k,int currSum,unordered_map<int,int>& prefSum){
        if (!root)
            return 0;
            
        int res=0;
        currSum+=root->data;
        
        if (currSum==k)
            res++;
            
        res+=prefSum[currSum-k];
        prefSum[currSum]++;
        
        res+=sumKRec(root->left,k,currSum,prefSum);
        res+=sumKRec(root->right,k,currSum,prefSum);
        
        prefSum[currSum]--;
        
        return res;
    }
    int sumK(Node *root, int k) {
        // code here
        unordered_map<int,int> prefSum;
        
        return sumKRec(root,k,0,prefSum);
    }
};