class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // vector<pair<int,int>> vp;
        int n = capacity.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<n; i++){
            pq.push(capacity[i]-rocks[i]);
        }
        
        int ans = 0;
        while(!pq.empty() && additionalRocks > 0){
            int needed = pq.top();
            
            if(needed <= additionalRocks){
                ans++;
                additionalRocks -= needed;
            }
            else if(needed == 0)
                ans++;
            else
                break;
            
            pq.pop();
        }
        
        return ans;
    }
};