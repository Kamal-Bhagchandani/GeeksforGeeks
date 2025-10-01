/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-bonus-problem/problem/roman-number-to-integer3201
*/

class Solution {
public:
    int romanToDecimal(string &s) {
        unordered_map<char,int> mp={
                {'I',1},
                {'V',5},
                {'X',10},
                {'L',50},
                {'C',100},
                {'D',500},
                {'M',1000}
        };
        
        int res=0;
        
        int i=0;
        
        while(i<s.size()){
            if(i+1<s.size() && mp[s[i]]<mp[s[i+1]]){
                res+=mp[s[i+1]]-mp[s[i]];
                i++;
            }
            else{
                res+=mp[s[i]];
            }
            i++;
        }
        
        return res;
    }
};