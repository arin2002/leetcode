class KthLargest {
public:
    
    priority_queue <int, vector<int>, greater<int> > pq;
    int n;
    
    KthLargest(int k, vector<int>& nums) {
        for(auto it : nums)
            pq.push(it);
        
        n = k;
        while(pq.size()>k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        
        while(pq.size()>n)
            pq.pop();
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */