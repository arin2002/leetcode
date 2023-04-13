class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> v(10,0);
        
        for(auto &it: num)
            v[it-'0']++;
        
        
        int single = -1;
        string ans = "";
        for(int i = 9; i>=0; i--){
            
            // ans empty ha aur zero aa rahe
            if(ans.size() == 0 && i == 0)
                continue;
            
            while(v[i] > 1){
                ans.push_back(i+'0');
                v[i] -= 2;
            }
            
            // this is for max element
            // like saare even pair ho gaye ab odd laga denge last mai
            if(v[i] == 1 && single == -1) single = i;
        }
        
        string res = string(ans.rbegin(),ans.rend());
        
        if(ans.empty() && single== -1) return "0";
        
        if(single!=-1)
            ans.push_back(single+'0');

        ans += res;
        return ans;
    }
};