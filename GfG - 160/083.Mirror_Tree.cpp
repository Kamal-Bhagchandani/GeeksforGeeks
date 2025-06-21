/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/mirror-tree
*/

/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if (!node)
            return;
            
        mirror(node->left);
        mirror(node->right);
        
        Node* temp=node->left;
        node->left=node->right;
        node->right=temp;
    }
};