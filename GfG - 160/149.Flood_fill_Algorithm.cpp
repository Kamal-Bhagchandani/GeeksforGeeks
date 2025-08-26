/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/flood-fill-algorithm1856
*/

class Solution {
  public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor) {
        // Base cases
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
        if (image[sr][sc] != originalColor || image[sr][sc] == newColor) return;

        image[sr][sc] = newColor;   // Change color
        
        dfs(image, sr - 1, sc, originalColor, newColor);
        dfs(image, sr + 1, sc, originalColor, newColor);
        dfs(image, sr, sc - 1, originalColor, newColor);
        dfs(image, sr, sc + 1, originalColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor != newColor) {
            dfs(image, sr, sc, originalColor, newColor);
        }
        return image;
    }
};