class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        
        function<int(int)>solve = [&](int n){
            int t = 0;
            
            while(n){
                int bit = n&1;
                if(bit == 1)
                    t++;
                
                n /= 2;
            }
            
            return t;
        };
        
        sort(arr.begin(),arr.end(),[&](auto a, auto b){
           if(solve(a) == solve(b))
               return a < b;
            
            return solve(a)<solve(b);
        });

        return arr;
    }
};