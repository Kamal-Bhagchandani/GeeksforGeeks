/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/get-minimum-element-from-stack
*/

class Solution {
  public:
    stack<int> st;
    int minVal;
    Solution() {
        // code here
        int minVal=-1;
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(st.empty()){
            st.push(x);
            minVal=x;
        }
        else{
            if(x>minVal)
                st.push(x);
            else{
                st.push(2*x-minVal);
                minVal=x;
            }
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(st.empty()) return;
        int top=st.top();
        st.pop();
        if(top<minVal)
            minVal=2*minVal-top;
    }

        
    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.empty()) return -1;
        
        int top=st.top();
        return (top<minVal)? minVal : top ;
    }
        

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(st.empty()) return -1;
        return minVal;
    }
};