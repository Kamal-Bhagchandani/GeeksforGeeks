/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/longest-valid-parentheses5657
*/

class Solution {
  public:
    int maxLength(string& s) {
        // code here
        stack<int> st;
        st.push(-1);
        
        int res=0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='(')
                st.push(i);
                
            else{
                st.pop();
                
                if(st.empty())
                    st.push(i);
                else
                    res = max(res,i-st.top());
            }
        }
        return res;
    }
};