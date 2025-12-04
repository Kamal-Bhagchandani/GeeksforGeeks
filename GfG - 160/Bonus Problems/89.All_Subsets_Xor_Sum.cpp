/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-bonus-problems/problem/sum-of-xor-of-all-possible-subsets
*/

class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size();
        int bits = 0;
        
        // Compute OR of all elements
        for(int x : arr)
            bits |= x;
        
        // Each bit contributes 2^(n-1) times
        return bits * pow(2, n - 1);
    }
};
