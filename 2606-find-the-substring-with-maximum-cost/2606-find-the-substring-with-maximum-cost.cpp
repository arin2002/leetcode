class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26,0);
        
        for(int i = 0; i<26; i++){
            v[i] = i+1;
        }
        
        int i = 0;
        for(auto &it:chars){
            v[it-'a'] = vals[i++]; 
        }
        
        int sum = 0, ans = 0;
        for(auto &it: s){
            sum += v[it-'a'];
            
            ans = max(ans,sum);
            
            if(sum<0){
                sum = 0;
            }
        }
        
        return ans;
    }
};