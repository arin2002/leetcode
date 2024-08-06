class Solution {
public:
    int minimumPushes(string word) {
        int idx = 0, product = 1, ans = 0;
        int mp[26] = {0};
        int n = sizeof(mp)/ sizeof(mp[0]);
        for(auto c:word){
            mp[c - 'a']++;
        }
        sort(mp, mp+n); 
        for(int i=25; i>=0; i--){
            idx++;
            if(idx%9 == 0) {
                product++;
                idx = 1;
            }
            ans +=(mp[i]*product);
        }
        return ans;
    }
};
