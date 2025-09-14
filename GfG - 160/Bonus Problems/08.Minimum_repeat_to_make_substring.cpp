/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645
*/

class Solution {
  private:
    void computeLPS(string &s, vector<int> &lps){
        int len=0, idx=1;
        lps[0]=0;
        
        while(idx<s.size()){
            if(s[idx]==s[len]){
                len++;
                lps[idx]=len;
                idx++;
            }
            else{
                if(len==0){
                    lps[idx]=0;
                    idx++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
    }
    bool KMPSearch(string &text, string &pat, vector<int> &lps, int rep){
        int n=text.size(),m=pat.size();
        int i=0,j=0;
        
        while(i<n*rep){
            if(text[i%n]==pat[j]){
                i++;
                j++;
                if(j==m)
                    return true;
            }
            else{
                if(j!=0)
                    j=lps[j-1];
                else
                    i++;
            }
        }
        
        return false;
    }
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        
        vector<int> lps(m);
        computeLPS(s2,lps);
        
        int x=(m+n-1)/n;
        
        if(KMPSearch(s1,s2,lps,x)){
            return x;
        }
        if(KMPSearch(s1,s2,lps,x+1)){
            return x+1;
        }
        
        return -1;
    }
};