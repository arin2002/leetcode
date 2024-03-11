class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,100);
        
        for(int i = 0; i<order.size(); i++){
            freq[order[i]-'a'] = i;
        }
        
        sort(s.begin(),s.end(),[&](char a, char b){
            return freq[a-'a']<freq[b-'a'];
        });
        
        return s;
    }
};