/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/decode-the-string2444
*/


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                res.push_back(s[i]);
            }
            else{
                string temp="";
                while(!res.empty()&&res.back()!='['){
                    temp=res.back()+temp;
                    res.pop_back();
                }
                res.pop_back();
                string num="";
                while(!res.empty()&& res.back()>='0' && res.back()<='9'){
                    num=res.back()+num;
                    res.pop_back();
                }
                int p=stoi(num);
                for(int j=0;j<p;j++){
                    res.append(temp);
                }
            }
        }
        return res;
    }
};