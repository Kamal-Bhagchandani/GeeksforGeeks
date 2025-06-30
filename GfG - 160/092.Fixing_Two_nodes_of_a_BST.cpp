/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/fixed-two-nodes-of-a-bst
*/

/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node *first,*prev,*middle,*last;
    void inorder(Node* root){
        if(!root)
            return;
        inorder(root->left);
        
        if(prev && root->data<prev->data){
            if(!first){
                first=prev;
                middle=root;
            }
            else
                last=root;
        }
        prev=root;
        
        inorder(root->right);
    }
    void correctBST(Node* root) {
        // add code here.
        first=middle=last=prev=NULL;
        inorder(root);
        
        if(first && last)
            swap(first->data,last->data);
        else if(first && middle)
            swap(first->data,middle->data);
    }
};