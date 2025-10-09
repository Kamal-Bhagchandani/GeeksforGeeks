/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/find-all-four-sum-numbers1732
*/

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        // code here
        vector<vector<int>> res;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-3;i++){
            if(i>0 and arr[i]==arr[i-1]) 
                continue;
            
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 and arr[j]==arr[j-1]) 
                    continue;
                    
                int k=j+1,l=n-1;
                
                while(k<l){
                    int sum=arr[i]+arr[j]+arr[k]+arr[l];
                    if(sum==target){
                        res.push_back({arr[i],arr[j],arr[k],arr[l]});
                        
                        k++;
                        l--;
                        
                        while(k<l && arr[k]==arr[k-1])
                            k++;
                            
                        while(k<l && arr[l]==arr[l+1])
                            l--;
                    }
                    else if(sum<target)
                        k++;
                    else
                        l--;
                }
            }
        }
        
        return res;
    }
};