class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v1(27,0);
        vector<int> v2(27,0);
        
        for(auto it : s)
            v1[it-'a']++;
        
        for(auto it : t){
            v2[it-'a']++;

        }
        
        for(auto it: t){
            if(v1[it-'a'] != v2[it-'a'])
                return it;
        }
        
        return 'c';
    }
};