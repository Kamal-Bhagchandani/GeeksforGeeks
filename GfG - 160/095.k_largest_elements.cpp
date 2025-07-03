/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/k-largest-elements4206
*/

class Solution {
  public:
    int partition(vector<int> &arr,int left,int right){
        int pivot=arr[right];
        int i=left;
        for(int j=left;j<right;j++){
            if(arr[j]>=pivot){
                swap(arr[i],arr[j]);
                i++;
            }
        }
        swap(arr[i],arr[right]);
        return i;
    }
    void quickSelect(vector<int> &arr,int left,int right,int k){
        int pivotIdx=partition(arr,left,right);
        int leftCnt=pivotIdx-left+1;
        
        if(leftCnt==k)
            return;
        if(leftCnt>k)
            quickSelect(arr,left,pivotIdx-1,k);
        else
            quickSelect(arr,pivotIdx+1,right,k-leftCnt);
    }
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        int n=arr.size();
        quickSelect(arr,0,n-1,k);
        
        vector<int> res(arr.begin(),arr.begin()+k);
        sort(res.rbegin(),res.rend());
        return res;
    }
};