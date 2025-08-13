/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/circular-tour-1587115620
*/

/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n=gas.size();
        int startIdx=0;
        int currGas=0;
        for(int i=0;i<n;i++){
            currGas+=gas[i]-cost[i];
            if(currGas<0){
                startIdx=i+1;
                currGas=0;
            }
        }
        currGas=0;
        for(int i=0;i<n;i++){
            int idx=(i+startIdx)%n;
            currGas+=gas[idx]-cost[idx];
            if(currGas<0) return -1;
        }
        return startIdx;
    }
};