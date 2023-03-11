class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), count  = 0;
        
        char prev = '0';
        for(auto &it :s){
            if(it != prev){
                count++;
                prev = it;
            }
        }
        
        return count;
    }
};