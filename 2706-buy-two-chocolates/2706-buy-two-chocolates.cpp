class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        
        int t = prices[0]+prices[1];
        int total = money - t;
        
        if(total >= 0)
            return total;
        
        return money;
    }
};