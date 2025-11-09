/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-bonus-problems/problem/get-max-from-stack
*/

class SpecialStack {
    stack<int> st;
    int maxEle;
  public:
    void push(int x) {
        // Push an element into the stack
        if(st.empty()){
            st.push(x);
            maxEle = x;
        }
        else if(x > maxEle){
            st.push(2 * x - maxEle);
            maxEle = x;
        }
        else{
            st.push(x);
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if(st.empty()) return;
        
        int t = st.top();
        st.pop();
        
        if(t > maxEle){
            maxEle = 2 * maxEle - t;
        }
    }

    int peek() {
        // Returns the top element
        if(st.empty()) return -1;
        
        int t = st.top();
        
        return (t > maxEle)? maxEle : t;
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMax() {
        // Return maximum element of Stack
        if(st.empty()) return -1;
        
        return maxEle;
    }
};