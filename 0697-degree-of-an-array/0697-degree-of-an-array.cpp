class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> ump, mp;
        
        int degree = 0;
        for(auto it : nums){
            ump[it]++;
            degree = max(ump[it],degree);
        }
        
        int ans = INT_MAX, i = 0, flag = 0;
        for(int j = 0; j<nums.size(); j++){
            if(!flag)
            mp[nums[j]]++;
            
            if(mp[nums[j]] == degree){
                cout<<j<<" "<<i<<endl;
                ans = min(ans,j-i+1);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                flag=true;
                j--;
                i++;
            }
            else{
                flag = false;
            }
        }
        
        return ans;
    }
};