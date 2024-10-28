class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
    unordered_set<int>st(nums.begin(),nums.end());
    int res=0;
    for(int &num:nums){
        int ans=0;
        long long currval=num;
        while(st.find(currval)!=st.end()){
            ans++;
            if(currval*currval>1e5) break;
            currval*=currval;
        }
        res=max(ans,res);
    }
return res<2?-1:res;
    }
};
