class NumArray {
public:
    vector<int> pre,suff;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre.resize(n);
        suff.resize(n);
        
        pre[0] = nums[0];
        for(int i = 1; i<n; i++)
            pre[i] = pre[i-1]+nums[i];
        
        suff[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            suff[i] = suff[i+1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left-1 < 0)
            return pre[right];

        return pre[right]-pre[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */