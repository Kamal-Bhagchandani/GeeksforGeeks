/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-bonus-problem/problem/corona-vaccine--141631
*/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
   int minVaccine(Node* root, int &res){
        if(!root) return 1;
        
        int left = minVaccine(root->left,res);
        int right = minVaccine(root->right,res);
        
        if(left == 0 || right == 0){
            res++;
            return 2;
        }
        
        if(left == 2 || right == 2)
            return 1;
        
        return 0;
   }
  public:
    int supplyVaccine(Node* root) {
        // Your code here
        int res = 0;
        
        if(minVaccine(root,res) == 0)
            res++;
        
        return res;
    }
};