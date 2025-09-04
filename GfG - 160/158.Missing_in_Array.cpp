/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/missing-number-in-array1416
*/

class Solution{
  public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;
        int xor1 = 0, xor2 = 0;

        for (int i = 0; i < n - 1; i++) {
            xor2 ^= arr[i];
        }

        for (int i = 1; i <= n; i++) {
            xor1 ^= i;
        }

        return xor1 ^ xor2;
    }
}