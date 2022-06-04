class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> v1,v2;
        
        for(int i = 0; i<n; i++)
        {
            if(i%2 == 0)
                v1.push_back(nums[i]);
            else
                v2.push_back(nums[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.rbegin(),v2.rend());
        //reverse(v2.begin(),v2.end());
        int j = 0, k =0;
        for(int i = 0 ; i<n;i++)
        {
            if(i %2 == 0)
                nums[i] = v1[j++];
            else 
                nums[i] = v2[k++];
        }
        
        return nums;
    }
};