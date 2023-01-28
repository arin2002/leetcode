class SummaryRanges {
public:
    
    set<int> st;
    SummaryRanges() {
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if(!st.size())
            return {};
        
        vector<vector<int>> ans;
        
        int left = -1, right = -1;
        for(auto it : st){
            if(left<0){
                left = right = it;
            }
            else if(it == right+1){
                right = it;
            }
            else{
                ans.push_back({left,right});
                left = right = it;
            }
        }
        
        ans.push_back({left, right});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */