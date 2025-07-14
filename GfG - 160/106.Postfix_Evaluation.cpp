/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/evaluation-of-postfix-expression1735
*/

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        
        for(int i=0;i<arr.size();i++){
            string token=arr[i];
            
            if (token!="*" && token !="/" && token!="+" && token!="-")
                st.push(stoi(token));
            else{
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                if(token=="*"){
                    st.push(val1*val2);
                }
                else if(token=="/"){
                    st.push(val2/val1);
                }
                else if(token=="+"){
                    st.push(val1+val2);
                }
                else{
                    st.push(val2-val1);
                }
            }
        }
        return st.top();
    }
};