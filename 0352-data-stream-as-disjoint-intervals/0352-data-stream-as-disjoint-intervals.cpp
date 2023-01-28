class SummaryRanges {
public:
    
    vector<int> v , vis;
    SummaryRanges() {
        vis.resize(10004);
    }
    
    void addNum(int value) {
        if(!vis[value]){
            v.push_back(value);
            vis[value]++;
        }
    }
    
    vector<vector<int>> getIntervals() {
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        int n = v.size();
        
        for(int i = 0; i<n; i++){
            int j = i;
            
            while(j+1<n && v[j]+1 == v[j+1]){
                j++;
            }
            
            if(j>i){
                ans.push_back({v[i],v[j]});
            }
            else{
                ans.push_back({v[i],v[i]});
            }
            
            i = j;
        }
        
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */