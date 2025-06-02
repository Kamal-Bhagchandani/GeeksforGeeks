/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/product-array-puzzle4525
*/

// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> prodArr(n);
        int totalProd=1,cnt0=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]!=0)
                totalProd*=arr[i];
            else
                cnt0++;
        }
        
        for(int i=0;i<n;i++){
            if(cnt0==0)
                prodArr[i]=totalProd/arr[i];
            else if (cnt0==1){
                if(arr[i]==0)
                    prodArr[i]=totalProd;
            }
        }
        return prodArr;
    }
};
