/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/queue-and-deque-bonus-problems/problem/minimum-number-of-k-consecutive-bit-flips--171650
*/

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int res = 0, flag = 0;
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(i >= k){
                flag ^= q.front();
                q.pop();
            }
            
            if(flag == 1)
                arr[i] ^= 1;
            
            if(arr[i] == 0){
                if(i + k > n)
                    return -1;
                
                res++;
                flag ^= 1;
                q.push(1);
            }
            else{
                q.push(0);
                
            }
        }
        
        return res;
    }
};