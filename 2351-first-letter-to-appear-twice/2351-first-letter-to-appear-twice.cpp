class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<int,int> ump;
        
        for(auto it:s){
            auto a = ump.find(it);
            
            if(a != ump.end())
                return a->first;
            
            ump[it]++;
        }
        
        return 0;
    }
};