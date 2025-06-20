/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/diameter-of-binary-tree
*/

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    int diameterRec(Node* root,int& res){
        if(root==nullptr)
            return 0;
            
        int lHeight=diameterRec(root->left,res);
        int rHeight=diameterRec(root->right,res);
        
        res=max(res,lHeight+rHeight);
        
        return 1+max(lHeight,rHeight);
    }
    int diameter(Node* root) {
        // Your code here
        int res=0;
        diameterRec(root,res);
        return res;
    }
};