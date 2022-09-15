class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        
        
        vector<int> ans;
        if(n%2 != 0)
            return ans;
        
        sort(changed.begin(),changed.end());
        unordered_map<int,int> ump;
        vector<int> temp;
        for(int i = 0; i<n; i++){
            ump[changed[i]]++;
        }
        
        for(int i = 0; i<n; i++){
            if(ump[changed[i]] == 0)
                    continue;
            
            if(ump.find(changed[i]*2) != ump.end()){
                ans.push_back(changed[i]);
                ump[changed[i]*2]--;
                ump[changed[i]]--;
            }
            else{
                ans = temp;
                break;
            }
        }
        if(ans.size() == n/2)
            return ans;
        return temp;
    }
};