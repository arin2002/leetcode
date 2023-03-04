class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> vis(26);
        
        int ans = 0;
        for(auto it : s)
            vis[it-'a']++;
        
        
        for(auto it : t){
            if(vis[it-'a']){
                vis[it-'a']--;
            }
            else
                ans++;
        }
        
        for(auto it : vis){
            if(it)
                ans += it;
        }
        
        return ans;
    }
};