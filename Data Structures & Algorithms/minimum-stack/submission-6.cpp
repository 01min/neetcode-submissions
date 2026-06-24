class MinStack {
public:
    stack<int>st;stack<int>minst;
    MinStack() {}
    
    void push(int val) {
        if((!minst.empty())&&val<minst.top()){minst.push(val);}
        else if(minst.empty()){minst.push(val);}
        else{minst.push(minst.top());}
        
        st.push(val);
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
