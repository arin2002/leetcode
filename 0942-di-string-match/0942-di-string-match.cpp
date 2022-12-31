class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> v;
        
        int i = 0, j = s.size();
        for(auto it : s){
            if(it == 'I'){
                v.push_back(i++);
            }
            else{
                v.push_back(j--);
            }
        }
        
        
        if(s[s.size()-1] == 'I')
            v.push_back(v[s.size()-1]+1);
        else
            v.push_back(v[s.size()-1]-1);
        
        return v;
    }
};