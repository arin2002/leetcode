class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = travel.size();
        vector<int> prefix(n);
        prefix[0] = travel[0];
        
        for(int i = 1; i<n; i++)
            prefix[i] = travel[i]+prefix[i-1];
        
        int ans = 0, g = 0, p = 0, m = 0;
        for(int i = 0; i<=n; i++){
            string s = garbage[i];
            // kaha tak max jayega vo truck apna
            for(auto &it : s){
                if(it == 'G') g = i;
                if(it == 'P') p = i;
                if(it == 'M') m = i;
            }
            
            // 1 sec wala time idhar
            ans += s.size();
        }
        
        if(g >= 1) ans += prefix[g-1];
        if(p >= 1) ans += prefix[p-1];
        if(m >= 1) ans += prefix[m-1];
        
        return ans;
    }
};