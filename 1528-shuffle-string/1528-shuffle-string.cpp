class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string st(indices.size(),'a');
        
        int i = 0;
        for(auto it : indices){
            // cout<<it<<i<<endl;
            st[it] = s[i++];
        }
        
        return st;
    }
};