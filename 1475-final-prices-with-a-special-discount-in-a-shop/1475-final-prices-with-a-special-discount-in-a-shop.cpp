class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> S;
        vector<int> output(prices);
        for(int i = 0; i<prices.size(); i++) {
            while(!S.empty() && prices[S.top()] >= prices[i]) {
                output[S.top()] -= prices[i]; 
                S.pop();
            }
            S.push(i);
        }
        return output;
    }
};
