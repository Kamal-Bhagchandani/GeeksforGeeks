/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/number-to-words0335
*/

// User function template for C++

class Solution {
  public:
    string convertToWords(int n) {
        // code here
        if(n==0) return "Zero";
        vector<string> units={
            "","One","Two","Three",
            "Four","Five","Six","Seven",
            "Eight","Nine","Ten","Eleven",
            "Twelve","Thirteen","Fourteen","Fifteen",
            "Sixteen","Seventeen","Eighteen","Nineteen"
        };
        vector<string> tens={
            "","","Twenty","Thirty","Forty",
            "Fifty","Sixty","Seventy","Eighty","Ninety"
        };
        vector<string> multiplier={"","Thousand","Million","Billion"};
        string res="";
        int group=0;
        while(n>0){
            if(n%1000!=0){
                int value=n%1000;
                string temp="";
                if(value>=100){
                    temp=units[value/100]+" Hundred ";
                    value%=100;
                }
                if(value>=20){
                    temp+=tens[value/10]+" ";
                    value%=10;
                }
                if(value>0){
                    temp+=units[value]+" ";
                }
                temp+=multiplier[group]+" ";
                res=temp+res;
            }
            n/=1000;
            group++;
        }
        while(res.back()==' ') res.pop_back();
        return res;
    }
};