class Solution {
public:
    int maxIceCream(vector<int>& costs, long long coins) {        
        // sort(costs.begin(),costs.end());
        vector<long long> v(1e5+1,0);
        
        for(auto it: costs)
            v[it]++;
        
        long long ans = 0, ind = 1;
    
        while(ind <= 1e5){
            if(v[ind] != 0){
                if(coins >= (ind*v[ind])){
                    coins -= (ind*v[ind]);
                    ans += v[ind];
                    ind++;
                }
                else if (coins >= ind){
                    coins -= ind;
                    v[ind]--;
                    ans++;
                }
                else
                    break;
            }
            else
                ind++;
        }
        
        return ans;
    }
};