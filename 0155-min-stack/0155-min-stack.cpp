class MinStack {
public:
    stack<pair<int,int>> st;
    int curr = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        // curr upadte kiya
        curr = min(val,curr);
        st.push({val,curr});
    }
    
    void pop() {
        // pop time dekh lena kahi min ho raha ho pop
        // update karna hoga
        st.pop();
        if(!st.empty()) {
        curr = st.top().second;
    } else {
        curr = INT_MAX;
    }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */