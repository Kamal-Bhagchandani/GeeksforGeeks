/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-bonus-problem/problem/distribute-candies-in-a-binary-tree
*/

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
    int solve(Node* root, int &ans) {
        
        if(!root)
            return 0;
        
        int left = solve(root -> left, ans);
        int right = solve(root -> right, ans);
        
        ans += abs(left) + abs(right);
        
        return root->data + left + right - 1;
        
    }
  public:
    int distCandy(Node* root) {
        // code here
        int ans = 0;
        solve(root,ans);
        
        return ans;
    }
};