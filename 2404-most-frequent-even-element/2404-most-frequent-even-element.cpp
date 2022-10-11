class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> ump;
        int ans = -1, temp = INT_MIN;
        for(auto i : nums){
            if((i&1) == 0){
                ump[i]++;
                
             if(ump[i] > temp){
                temp = ump[i];
                ans = i;
            }
            else if(ump[i] == temp)
                ans = min(ans,i);   
            }
        }
        
        // for(auto it : ump){
        //     if(it.second > temp){
        //         temp = it.second;
        //         ans = it.first;
        //     }
        //     else if(it.second == temp)
        //         ans = min(ans,it.first);
        // }
        return ans;
    }
};