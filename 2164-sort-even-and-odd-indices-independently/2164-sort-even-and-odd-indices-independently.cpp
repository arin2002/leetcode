class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i&1){
                odd.push_back(nums[i]);
            }
            else{
                even.push_back(nums[i]);
            }
        }
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end());
        int p = 0;
        for(int i=1;i<n;i+=2){
            nums[i] = odd[p++];
        }
        p = 0;
        for(int i=0;i<n;i+=2){
            nums[i] = even[p++];
        }
        return nums;
    }
};
