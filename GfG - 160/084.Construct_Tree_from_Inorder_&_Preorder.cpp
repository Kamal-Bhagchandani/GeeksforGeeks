/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/construct-tree-1
*/

// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTreeRec(int l,int h,vector<int> &preorder,unordered_map<int,int> &map,int &index){
        if (l>h)
            return NULL;
            
        int value=preorder[index];
        Node* root=new Node(value);
        index+=1;
        root->left=buildTreeRec(l,map[value]-1,preorder,map,index);
        root->right=buildTreeRec(map[value]+1,h,preorder,map,index);
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int index=0;
        int n=inorder.size();
        unordered_map<int,int> map;
        
        for(int i=0;i<n;i++){
            map[inorder[i]]=i;
        }
        Node* root=buildTreeRec(0,n-1,preorder,map,index);
        
        return root;
    }
};