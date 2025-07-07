/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/parenthesis-checker2744
*/

class Solution {
  public:
    bool isBalanced(string& k) {
        // code here
        stack<char> s;
        int n=k.size();
        
        for(int i=0;i<n;i++){
            
            if(k[i]=='(' || k[i]=='{' || k[i]=='['){
                s.push(k[i]);
            }
            
            else{
                
                if(!s.empty() && 
                    ((k[i]==')' && s.top()=='(') || 
                     (k[i]==']' && s.top()=='[') || 
                     (k[i]=='}' && s.top()=='{')))
                    s.pop();
                    
                else
                    return false;
            }
        }
        return s.empty();
    }
};