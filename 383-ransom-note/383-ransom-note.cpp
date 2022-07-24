class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> r(26,0), ma(26,0);
        
        int n = ransomNote.size();
        int m = magazine.size();
        
        if(n > m)
            return false;
        
        for(auto it : ransomNote)
            r[it-'a']++;
        
        // cout<<r[0];
        
        for(auto it: magazine)
            ma[it-'a']++;
        
        // cout<<ma[0];
        for(auto it : ransomNote){
            if(ma[it-'a']!=0 && r[it-'a'] !=0)
            {
                if(ma[it-'a'] - r[it-'a'] < 0)
                    return false;
                continue;
            }
            else 
                return false;
        }
        
        return true;
    }
};