class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s=(s+nums[j])%mod;
                v.push_back(s);
            }   
        }
        sort(v.begin(),v.end());int s=0;
        for(int i=left-1;i<right;i++){
            s=(s+v[i])%mod;
        }
        return s;
    }
};
