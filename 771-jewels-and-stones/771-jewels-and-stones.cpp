class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n  = stones.size();
        int m = jewels.size();
        int c = 0;
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(jewels[j] == stones[i]){
                    c++;
                    break;
                }
            }
        }
        
        return c;
    }
};