/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-possible-triangles-1587115620
*/

class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int res=0,n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=2;i<n;i++){
            int left=0,right=i-1;
            while(left<right){
                if(arr[left]+arr[right]>arr[i]){
                    res+=right-left;
                    right--;
                }
                else left++;
            }
        }
        return res;
    }
};
