/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/height-of-binary-tree
*/

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {    // Using Recursion:
  public:
    int height(Node* node) {
        // code here
        if(node==nullptr)
            return -1;
        
        int lHeight=height(node->left);
        int rHeight=height(node->right);
        
        return max(lHeight,rHeight)+1;
    }
};

class Solution {    //Using Queue:
  public:
    int height(Node* node) {
        // code here
        if(node==nullptr)
            return -1;
        queue<Node*> q;
        q.push(node);
        int depth=0;
        
        while(!q.empty()){
            int levelSize=q.size();
            for(int i=0;i<levelSize;i++){
                Node* curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            depth++;
        }
        return depth-1;
    }
};