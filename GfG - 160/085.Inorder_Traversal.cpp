/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/inorder-traversal
*/

/*
// Tree Node
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
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> res;
        Node* curr=root;
        while(curr){
            if (curr->left!=nullptr){
                Node* prev=curr->left;
                while(prev->right!=nullptr && prev->right!=curr)
                    prev=prev->right;
                if(prev->right==nullptr){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    res.push_back(curr->data);
                    curr=curr->right;
                }
            }
            else{
                res.push_back(curr->data);
                curr=curr->right;
            }
        }
        return res;
    }
};