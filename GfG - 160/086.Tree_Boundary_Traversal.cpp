/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/boundary-traversal-of-binary-tree
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
    bool isLeaf(Node* node){
        return node->left==nullptr && node->right==nullptr;
    }
    void collectBoundaryLeft(Node* root,vector<int>& res){
        if(root==nullptr || isLeaf(root)){
            return;
        }
        res.push_back(root->data);
        if(root->left)
            collectBoundaryLeft(root->left,res);
        else if(root->right)
            collectBoundaryLeft(root->right,res);
    }
    void collectLeaves(Node* root,vector<int>& res){
        if(root==nullptr)
            return;
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        collectLeaves(root->left,res);
        collectLeaves(root->right,res);
    }
    void collectBoundaryRight(Node* root,vector<int>& res){
        if(root==nullptr || isLeaf(root)){
            return;
        }
        if(root->right)
            collectBoundaryRight(root->right,res);
        else if(root->left)
            collectBoundaryRight(root->left,res);
        res.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(!root)
            return res;
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        collectBoundaryLeft(root->left,res);
        collectLeaves(root,res);
        collectBoundaryRight(root->right,res);
        return res;
    }
};