/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-bonus-problem/problem/create-a-spiral-matrix-of-nm-size-from-given-array
*/

class Solution {
  public:
    vector<vector<int>> spiralFill(int n, int m, vector<int> &arr) {
        // code here
        vector<vector<int>> res(n,vector<int>(m,-1));
        
        int top=0,bottom=n-1,left=0,right=m-1;
        int index=0;
        
        while(index<arr.size()){
            for(int j=left;j<right+1;j++){
                res[top][j]=arr[index];
                index++;
            }
            top++;
            
            for(int i=top;i<bottom+1;i++){
                res[i][right]=arr[index];
                index++;
            }
            right--;
            
            if(top<=bottom){
                for(int j=right;j>left-1;j--){
                    res[bottom][j]=arr[index];
                    index++;
                }
                bottom--;
            }
            
            if(left<=right){
                for(int i=bottom;i>top-1;i--){
                    res[i][left]=arr[index];
                    index++;
                }
                left++;
            }
        }
        return res;
    }
};
