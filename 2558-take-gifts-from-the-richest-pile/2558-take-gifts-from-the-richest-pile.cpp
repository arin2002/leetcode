class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<long long> pq;
        
        for(auto it : gifts)
            pq.push(it);
        
        
        for(int i = 0; i<k; i++){
            long long top = pq.top();
            pq.pop();
            pq.push(sqrt(top));
        }
        
        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};