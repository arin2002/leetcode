class MyCircularDeque {
public:
    vector<int> dq;
    int sz;
    int front;
    int rear;
    int current;

    MyCircularDeque(int k) {
        sz = k;
        dq.resize(k); 
        front = 0;
        rear = k - 1;
        current = 0;
    }
    
    bool insertFront(int value) {
        if (isFull())
            return false;
        front = (front - 1 + sz) % sz;
        dq[front] = value;
        current++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())
            return false;
        rear = (rear + 1) % sz;
        dq[rear] = value;
        current++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;
        front = (front + 1) % sz;
        current--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;
        rear = (rear - 1 + sz) % sz;
        current--;
        return true;
    }
    
    int getFront() {
        if (isEmpty())
            return -1;
        return dq[front];
    }
    
    int getRear() {
        if (isEmpty())
            return -1;
        return dq[rear];
    }
    
    bool isEmpty() {
        return current == 0;
    }
    
    bool isFull() {
        return current == sz;
    }
};
