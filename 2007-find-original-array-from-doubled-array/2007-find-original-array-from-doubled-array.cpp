class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        int n = changed.size();
        
        sort(changed.begin(),changed.end());
        
        if(n%2 != 0)
            return ans;
        
        unordered_map<int,int> ump;
        bool flag = false;
        for(auto it : changed){
            ump[it]++;
            if(it == 0)
                flag = true;
        }
        
        if(flag){
            if(ump[0]%2 != 0)
                return ans;
        }
        
        for(auto it : changed){
            if(ump[it] == 0)
                continue;
            
            auto i = ump.find(it*2);
            
            if(i!= ump.end()){
                if(i->second != 0){
                    ans.push_back(it);
                    ump[it*2]--;
                    ump[it]--;
                }
            }
        }
        
//         for(auto it: ans)
//             cout<<it<<" ";
        
        // cout<<ans.size();
        if(ans.size() != n/2)
            return {};
        
        return ans;
    }
};