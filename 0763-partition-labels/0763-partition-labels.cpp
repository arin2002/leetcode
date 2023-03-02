class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        
        vector<int> vis(27);
        for(int i = 0; i<s.size(); i++){
            vis[s[i]-'a'] = i;
        }
        
        int start = 0, end = 0;
        
        for(int i = 0; i<s.size(); i++){
            end = max(end,vis[s[i]-'a']);
            
            if(i == end){
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        
        return ans;
    }
};