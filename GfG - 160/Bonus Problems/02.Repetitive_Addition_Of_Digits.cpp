/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/repetitive-addition-of-digits2221
*/

class Solution {
  public:
    int recSum(int n){
        if(n==0) return 0;
        return n%10+recSum(n/10);
    }
    int singleDigit(int n) {
        // code here
        if(n<=9) return n;
        int sum=recSum(n);
        return singleDigit(sum);
    }
};