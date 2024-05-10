class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // max heap
        priority_queue<pair<double, pair<int, int>>> pq;
        
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                pq.push({(double)(arr[i]) / arr[j], {arr[i], arr[j]}});
                
                if(pq.size() > k)
                    pq.pop();
            }
        }
        
        vector<int> ans(2);
        ans[0] = pq.top().second.first;
        ans[1] = pq.top().second.second;
        
        return ans;
    }
};
