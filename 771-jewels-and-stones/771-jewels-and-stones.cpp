class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n  = stones.size();
        int m = jewels.size();
        int c = 0;
        unordered_map<char,int> mp;
        
        for(int i = 0; i<m; i++)
        {
            char d = jewels[i];
            mp[d]++;
        }
        
        for(int i = 0; i<n; i++)
        {
            char d = stones[i];
            auto it = mp.find(d);
            
            if(it!=mp.end())
                c++;
        }
        return c;
    }
};