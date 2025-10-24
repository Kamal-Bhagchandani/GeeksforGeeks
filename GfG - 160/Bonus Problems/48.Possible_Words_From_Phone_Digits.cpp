/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-bonus-problem/problem/possible-words-from-phone-digits-1587115620
*/

class Solution {
  private:
    void possibleWordsRec(vector<int> &arr, int index, string &prefix,
                            vector<string> &map, vector<string> & res){
        if(index == arr.size()){
            res.push_back(prefix);
            return;
        }
        int digit = arr[index];
        if(digit<2 || digit>9){
            possibleWordsRec(arr,index+1,prefix,map,res);
            return;
        }
        for(char ch : map[digit]){
            prefix.push_back(ch);
            possibleWordsRec(arr,index+1,prefix,map,res);
            
            // Backtracking to previous state
            prefix.pop_back();
        }
    }
  public:
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        vector<string> res;
        
        vector<string> map = {"", "", "abc", "def", "ghi","jkl",
                                "mno", "pqrs", "tuv", "wxyz"};
        
        string prefix = "";
        
        possibleWordsRec(arr,0,prefix,map,res);
        
        return res;
    }
};