class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans, freq(26);
        int n = s.size(), max_seen = 0; 
        
        for(int i = 0; i<n; i++)
            freq[s[i]-'a'] = i;
        
        int j = 0;
        for(int i = 0; i<n; i++){
            max_seen = max(max_seen,freq[s[i]-'a']);
            
            if(max_seen <= i){
                ans.push_back(i-j+1);
                j = i+1;
            }
        }
        
        return ans;
    }
};