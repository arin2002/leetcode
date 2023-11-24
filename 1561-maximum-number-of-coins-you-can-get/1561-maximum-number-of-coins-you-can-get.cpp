class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size(), ans = 0;
        
        sort(piles.begin(),piles.end());
        int l = 0, p = n-2, r = n-1;
        
        while(l<p){
            ans += piles[p];
            
            l++; p-=2;
        }
        
        return ans;
    }
};