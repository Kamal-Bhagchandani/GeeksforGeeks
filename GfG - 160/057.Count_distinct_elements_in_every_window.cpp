/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-distinct-elements-in-every-window
*/

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n=arr.size();
        vector<int> res;
        int l=0,r=k-1;
        unordered_map<int,int> m;
        for(int i=0;i<k;i++){
            m[arr[i]]++;
        }
        res.push_back(m.size());
        
        for(int i=k;i<n;i++){
            m[arr[i]]++;
            int start=i-k;  //window start
            m[arr[start]]--;
            if(m[arr[start]]==0) m.erase(arr[start]);
            res.push_back(m.size());
        }
        return res;
    }
};