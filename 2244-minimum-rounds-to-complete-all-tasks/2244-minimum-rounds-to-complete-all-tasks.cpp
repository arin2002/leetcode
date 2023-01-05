class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        
        unordered_map<int,int> ump;
        
        for(auto it : tasks){
            ump[it]++;
        }
        
        // for(auto [a,b] : ump){
        //     if(b == 1)
        //         return -1;
        // }    
        
        for(auto [a,b] : ump){
            
            if(b == 1)
                return -1;
            
            
            if(b%3 == 0)
                ans += (b/3);
            
            else
                ans += b/3+1;
        }
        
        return ans;
    }
};