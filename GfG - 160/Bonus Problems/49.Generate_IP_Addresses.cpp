/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-bonus-problem/problem/generate-ip-addresses
*/

/*complete the Function*/

class Solution {
  private:
    bool isValid(string &s){
        int n = s.size();
        
        if(n==1)
            return true;
            
        int val = stoi(s);
        
        if(s[0] == '0' || val > 255)
            return false;
            
        return true;
    }
    void generateIpRec(string &s, int index, string curr, int cnt, vector<string> &res){
        string temp = "";
        
        if(index >= s.size())
            return;
        
        if(cnt == 3){
            temp = s.substr(index);
            if(temp.size() <= 3 && isValid(temp))
                res.push_back(curr+temp);
            
            return;
        }
        
        for(int i = index; i < min(index+3,(int)s.size()); i++){
            temp += s[i];
            if(isValid(temp)){
                generateIpRec(s, i+1, curr+temp+'.', cnt+1, res);
            }
        }
    }
  public:
    vector<string> generateIp(string s) {
        // code here
        vector<string> res;
        
        generateIpRec(s, 0, "", 0, res);
        
        return res;
    }
};