class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // max heap
        vector<pair<double, pair<int, int>>> pq;
        
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                pq.push_back({(double)(arr[i]) / arr[j], {arr[i], arr[j]}});
                
            }
        }
        
        sort(pq.begin(),pq.end());
        auto pair = pq[k-1];
                
        return {pair.second.first,pair.second.second};
    }
};
