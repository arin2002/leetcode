class SeatManager {
public:
    
    int marker = 1;
    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
    }
    
    int reserve() {
        if(!pq.empty()){
            int res = pq.top();
            pq.pop();
            return res;
        }
        
        return marker++;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */