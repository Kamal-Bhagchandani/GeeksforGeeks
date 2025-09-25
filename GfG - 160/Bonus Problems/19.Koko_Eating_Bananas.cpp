/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-bonus-problems/problem/koko-eating-bananas
*/

class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int maxElement=*max_element(arr.begin(),arr.end());
        
        int low=1,high=maxElement;
        int ans=high;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int hours=0;
            for(int bananas : arr){
                hours += bananas / mid;
                if(bananas % mid!=0){
                    hours++;
                }
            }
            if(hours<=k){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        return ans;
    }
};