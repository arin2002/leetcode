class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> ump;
        
        for(auto i : s)
            ump[i]++;
        
        int count = 0;
        bool flag = true;
        for(auto it = ump.begin(); it!=ump.end(); it++)
        {
            if(it->second % 2 == 0)
                count+= it->second;
            
            else if(it->second % 2 !=0){
                count += it->second - 1;
            }
        }
        
        return count + (s.length()>count ? 1:0);
    }
};