class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0, n=nums.size();
        //Sum of first n numbers
		int act = (n*(n+1))/2;
        
		//Sum of elements of our vector
        for(int i=0;i<n;i++) sum+=nums[i];
        
        return act-sum;
    }
};
