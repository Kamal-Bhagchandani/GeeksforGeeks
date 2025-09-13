/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/string-palindromic-ignoring-spaces4723
*/

class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int l=0, r=s.size()-1;
        while(l<r){
            if(!isalnum(s[l])){
                l++;
            }
            else if(!isalnum(s[r])){
                r--;
            }
            else if(tolower(s[l])==tolower(s[r])){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};