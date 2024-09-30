class CustomStack {
public:
    vector<int> arr;
    int top;
    CustomStack(int maxSize) {
        arr.resize(maxSize, -1);
        top = -1;
    }
    
    void push(int x) {
        cout << "push called" << endl;
        if(top == arr.size() - 1){
            return;
        }
        top += 1;
        arr[top] = x;
    }
    
    int pop() {
        if(top == -1) return -1;
        int x = arr[top];
        arr[top] = -1;
        top -= 1;
        return x;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i <= min(k - 1, top); i++){
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
