class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        int counts = 0;
        
        for(auto it : stones){
            counts += count(jewels.begin(),jewels.end(),it);
        }
        
        return counts;
    }
};