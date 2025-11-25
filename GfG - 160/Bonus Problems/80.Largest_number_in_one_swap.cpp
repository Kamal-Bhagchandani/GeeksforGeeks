/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-bonus-problems/problem/largest-number-in-one-swap1520
*/

class Solution {
  public:
    string largestSwap(string &s) {
        char maxDigit = '0';
        int maxIndex, l, r;
        
        l = r = maxIndex = -1;
        
        for(int i = s.size(); i >= 0; i--){
            if(s[i]>maxDigit){
                maxDigit = s[i];
                maxIndex = i;
            }
            else if(s[i] < maxDigit){
                l = i;
                r = maxIndex;
            }
        }
        
        if(l == -1)
            return s;
        
        swap(s[l],s[r]);
        
        return s;
    }
};