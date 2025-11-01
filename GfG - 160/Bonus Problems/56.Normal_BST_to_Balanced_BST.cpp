/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-bonus-problem/problem/normal-bst-to-balanced-bst
*/

/*Structure of the Node of the BST is as
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
    void storeInorder(Node* root, vector<int> &nodes){
        if(!root) return;
        
        storeInorder(root->left, nodes);
        nodes.push_back(root->data);
        storeInorder(root->right, nodes);
    }
    
    Node* buildBalancedTree(vector<int> &nodes, int start, int end){
        if(start>end)
            return nullptr;
        
        int mid = start + (end - start) / 2;
        Node* root = new Node(nodes[mid]);
        
        root->left = buildBalancedTree(nodes, start, mid - 1);
        root->right = buildBalancedTree(nodes, mid + 1, end);
        
        return root;
    }
    
  public:
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> nodes;
        
        storeInorder(root,nodes);
        
        return buildBalancedTree(nodes, 0, nodes.size() - 1);
    }
};