class Solution {
public:
    bool checkIfPangram(string s) {
        int n = s.size();
        
        if(n < 26)
            return 0;
        
        vector<int> v(26,0);
        for(auto i: s){
            v[i-'a']++;
        }
        
        for(auto i : v){
            if(i == 0)
                return false;
        }
        
        return true;
    }
};