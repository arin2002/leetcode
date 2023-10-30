class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<pair<int,int>> vp;
        int n = arr.size();
        
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
        
        
        for(int i = 0; i<n; i++){
            vp.push_back({solve(arr[i]),arr[i]});
        }
        
        sort(vp.begin(),vp.end(),[&](auto a, auto b){
            if(a.first == b.first){
                return a.second<b.second;
            }
            
            return a.first < b.first;
        });
        
        for(auto it: vp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};