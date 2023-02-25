class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        
        priority_queue<int> pq;
        unordered_map<int,int> ump;
        
        for(auto it: score){
            pq.push(it);
        }
        
        int i = 1;
        while(!pq.empty()){
            ump[pq.top()] = i++;
            pq.pop();
        }
        
        for(auto it : score){
            if(ump[it] == 1){
                ans.push_back("Gold Medal");
            }
            else if(ump[it] == 2){
                ans.push_back("Silver Medal");
            }
            else if(ump[it] == 3){
                ans.push_back("Bronze Medal");
            }
            else{
                ans.push_back(to_string(ump[it]));
            }
        }
        
        return ans;
    }
};