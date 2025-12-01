/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tries-bonus-problems/problem/maximum-xor-with-an-element-from-array
*/

class Solution {
  public:
    struct Node{
        Node* child[2];
        Node(){ child[0] = child[1] = nullptr;}
    };
    
    Node* root;
    
    Solution(){
        root = new Node();
    }
    
    void insert(int x){
        Node* curr = root;
        for(int b = 31; b >=0; b--){
            int bit = (x >> b) & 1;
            if(!curr->child[bit]){
                curr->child[bit] = new Node();
            }
            curr = curr->child[bit];
        }
    }
    
    int getMaxXor(int x){
        Node* curr = root;
        int ans = 0;
        
        for(int i = 31; i >= 0; i--){
            int bit = (x >> i) & 1;
            
            if(curr->child[1 - bit]){
                ans |= (1 << i);
                curr = curr->child[1 - bit];
            }
            else{
                curr = curr->child[bit];
            }
        }
        
        return ans;
    }
    
    vector<int> maxXor(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        int q = queries.size();
        
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> qlist;
        for(int i = 0; i < q; i++){
            qlist.push_back({queries[i][1], queries[i][0], i});
        }
        
        sort(qlist.begin(), qlist.end());
        
        vector<int> ans(q,-1);
        int idx = 0;
        
        for(auto &qr : qlist){
            int mi = qr[0];
            int xi = qr[1];
            int qi = qr[2];
            
            while(idx < n && arr[idx] <= mi){
                insert(arr[idx]);
                idx++;
            }
            
            if(idx == 0)
                ans[qi] = -1;
            else
                ans[qi] = getMaxXor(xi);
        }
        return ans;
    }
};