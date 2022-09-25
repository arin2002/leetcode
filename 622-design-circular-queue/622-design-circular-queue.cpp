class MyCircularQueue {
public:
    vector<int> q;
    int f = 0, r = 0, n = 0;
    MyCircularQueue(int k) {
        vector<int> temp(k,0);
        q = temp;
        n = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        int ind = (f + r)%n;
        r++;
        q[ind] = value;
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        
        f = (f+ 1)%n;
        r--;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        
        return q[f];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        
        return q[(f + r - 1) % n];
    }
    
    bool isEmpty() {
        return !r;
    }
    
    bool isFull() {
        return r == n;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */