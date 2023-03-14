class Solution {
public:
    string customSortString(string s, string t) {
        sort(t.begin(),t.end(),[&](auto a, auto b){
            return s.find(a)<s.find(b);
        });
        
        return t;
    }
};