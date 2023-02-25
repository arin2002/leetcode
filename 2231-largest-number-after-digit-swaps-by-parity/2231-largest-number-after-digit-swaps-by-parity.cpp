class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> even, odd;
        
        int n = num, ans = 0;
        vector<int> nums;
        
        while(n){
            
            int digi = n%10;
            if(digi%2)
                odd.push(digi);
            else
                even.push(digi);
            
            nums.push_back(n%10);
            n/=10;
        }
        
        reverse(nums.begin(),nums.end());
        
        for(auto &it : nums){
            if(it%2){
                it = odd.top();
                odd.pop();
            }
            else{
                it = even.top();
                even.pop();
            }
        }
        
        for(auto it : nums){
            ans = ans*10+it;
        }
        
        return ans;
    }
};