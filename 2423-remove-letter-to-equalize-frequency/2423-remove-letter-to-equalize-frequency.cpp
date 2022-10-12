class Solution {
public:
    bool equalFrequency(string s) {
        int n = s.size();
        unordered_map<int,int> ump;
        
        for(auto it : s){
            ump[it]++;
        }
        
        for(auto it : s){
            ump[it]--;
            
            if(ump[it] == 0)
                ump.erase(it);
            
            int i = 0, prev = 0, flag = 0;
            for(auto it : ump){
                if(i == 0){
                    prev = it.second;
                    i++;
                }
                else if(prev != it.second){
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0)
                return true;
            
            ump[it]++;
        }
        
        return false;
    }
};