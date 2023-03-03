class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastInd(27);
        
        int i = 0;
        for(auto it : s)
            lastInd[it-'a'] = i++;
        
        
        int start = 0, end = 0;
        vector<int> ans;
        
        for(i = 0; i<s.size(); i++){
            end = max(end, lastInd[s[i]-'a']);
            
            if(i == end){
                ans.push_back(end-start+1);
                start = i+1;
            }
        }
        
        return ans;
    }
};