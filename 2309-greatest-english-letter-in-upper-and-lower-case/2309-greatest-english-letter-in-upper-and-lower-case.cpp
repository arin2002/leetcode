class Solution {
public:
    string greatestLetter(string s) {
        unordered_map<char,int> ump;
        
        string ans ="";
        for(auto it :s){
            ump[it]++;
        }
        
        sort(s.begin(),s.end());
        
        
        for(auto it:s){
            if(it >= 'a' && it<='z'){
                auto i = ump.find(it-32);
                
                if(i != ump.end())
                    ans = i->first;
            }
        }
        
        return ans;
    }
};