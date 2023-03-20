class Solution {
public:
    
    bool static cmp(vector<int> a, vector<int> b){
        return a[1] >= b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // vector<pair<int,int>> vp;
        
        // for(auto &it : boxTypes){
        //     vp.push_back({it[1],it[0]});
        // }
        
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans = 0;
        
        for(auto &it: boxTypes){
            if(it[0] >= truckSize){
                ans += truckSize*it[1];
                break;
            }
            else{
                ans += it[0]*it[1];
                truckSize -= it[0];
            }            
        }
        
        return ans;
    }
};