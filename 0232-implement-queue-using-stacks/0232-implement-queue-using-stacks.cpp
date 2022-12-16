class MyQueue {
public:
    
    stack<int> s;
    stack<int> s1;
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!s.empty()) {
            s1.push(s.top());
            s.pop();
        }
      s1.push(x);
      
        while(!s1.empty())
        {
            s.push(s1.top());
            s1.pop();
        }
    }
    
    int pop() {
        int x = s.top();
        s.pop();
        return x;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        if(s.empty())
            return true;
        else
            return false;
    }
};