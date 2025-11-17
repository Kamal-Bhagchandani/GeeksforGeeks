/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dp-bonus-problems/problem/ugly-number-ii
*/

class Solution {
  public:
    int uglyNumber(int n) {
        // code here
        vector<int> arr(n);
        
        int ind2 = 0, ind3 = 0, ind5 = 0;
        int mul2 = 2, mul3 = 3, mul5 = 5;
        
        int nextNum = 1;
        arr[0] = 1;
        
        for(int i = 1; i < n; i++){
            nextNum = min({mul2, mul3, mul5});
            arr[i] = nextNum;
            
            if(nextNum == mul2){
                ind2++;
                mul2 = arr[ind2] * 2;
            }
            if(nextNum == mul3){
                ind3++;
                mul3 = arr[ind3] * 3;
            }
            if(nextNum == mul5){
                ind5++;
                mul5 = arr[ind5] * 5;
            }
        }
        
        return nextNum;
    }
};