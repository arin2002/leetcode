class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> vp;
        
        for(auto &it : boxTypes){
            vp.push_back({it[1],it[0]});
        }
        
        sort(vp.begin(),vp.end(), greater<pair<int,int>>());
        int ans = 0;
        
        for(auto &it: vp){
            if(it.second > truckSize){
                ans += truckSize*it.first;
                break;
            }
            else{
                ans += it.second*it.first;
                truckSize -= it.second;
            }            
        }
        
        return ans;
    }
};