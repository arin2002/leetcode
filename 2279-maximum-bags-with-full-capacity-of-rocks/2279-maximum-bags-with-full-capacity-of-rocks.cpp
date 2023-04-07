class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<pair<int,int>> vp;
        
        int n = rocks.size();
        for(int i = 0; i<n; i++){
            vp.push_back({capacity[i],rocks[i]});
        }
        
        sort(vp.begin(),vp.end(),[&](auto &a, auto &b){
            return a.first - a.second < b.first - b.second;
        });
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            int req = vp[i].first - vp[i].second;
            
            if(req > additionalRocks)
                break;
            else{
                additionalRocks -= req;
                ans++;
            }
        }
        
        return ans;
    }
};