class Solution {
public:
    int partitionString(string s) {
        vector<int> v(26,-1);
        int n = s.size();
        
        int ans = 1, start = 0;
        
        // 1 is taken bcz 1st string is taken in consideration
        for(int i = 0; i<n; i++){
            if(v[s[i]-'a'] >= start){
                ans++;
                start = i;
            }
            v[s[i]-'a'] = i;
        }
                
        return ans;
    }
};