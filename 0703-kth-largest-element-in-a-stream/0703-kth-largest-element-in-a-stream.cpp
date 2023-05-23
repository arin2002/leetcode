class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int n;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(auto &it: nums){
            if(pq.size()<k){
                pq.push(it);
            }
            else{
                int top = pq.top();
                if(pq.top()<it){
                    pq.pop();
                    pq.push(it);
                }
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size()>n)
            pq.pop();
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */