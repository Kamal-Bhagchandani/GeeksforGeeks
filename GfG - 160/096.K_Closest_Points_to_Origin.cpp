/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/k-closest-points-to-origin--172242
*/

class Solution {
  public:
    int squaredDis(vector<int> &point){
        return point[0]*point[0]+point[1]*point[1];
    }
    
    int partition(vector<vector<int>> &points,int left,int right){
        vector<int> pivot=points[right];
        int i=left;
        for(int j=left;j<right;j++){
            if(squaredDis(points[j])<=squaredDis(pivot)){
                swap(points[i],points[j]);
                i++;
            }
        }
        swap(points[i],points[right]);
        return i;
    }
    
    void quickSelect(vector<vector<int>> &points,int left, int right,int k){
        if(left<=right){
            int pivotIdx=partition(points,left,right);
            int leftCnt=pivotIdx-left+1;
            if(leftCnt==k)
                return;
            if(leftCnt>k)
                quickSelect(points,left,pivotIdx-1,k);
            else
                quickSelect(points,pivotIdx+1,right,k-leftCnt);
        }
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        quickSelect(points,0,points.size()-1,k);
        
        return vector<vector<int>> (points.begin(),points.begin()+k);
    }
};