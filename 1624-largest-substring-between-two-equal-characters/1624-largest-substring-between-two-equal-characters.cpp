class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int ans = -1;
        for(int i = 0; i < n; ++i){
            if(!mp.count(s[i])){
                mp[s[i]] = i;
            }
            else{
                ans = max(ans, i - mp[s[i]] - 1);
            }
        }
        return ans;
    }
};
