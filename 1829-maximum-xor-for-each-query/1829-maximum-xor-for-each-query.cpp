class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int t=0;
        vector<int> xors(n);//prefix of all xor
        for(int i=0;i<n;i++){
            if(i!=0)xors[i]=xors[i-1];
            xors[i]^=nums[i];
        }

        vector<int> ans(n,0);//checking the neccesaasry bits for all the prefixs
        for(int j=0;j<maximumBit;j++)
            for(int i=0;i<n;i++)
                if(((xors[i]>>j)&1)==0)ans[i]+=(1<<j);

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
