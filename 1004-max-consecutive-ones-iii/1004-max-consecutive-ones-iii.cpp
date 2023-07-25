class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, count = 0;
        int start = 0, n = nums.size();
        queue<int> q;
        
        for(int i = 0; i<n; i++){
            if(nums[i] == 0 && k >= 0){
                k--;
                // while(k < 0){
                //     if(nums[start++] == 0)
                //         k++;
                // }
                q.push(i);
                if(k<0){
                    start = q.front()+1;
                    k++;
                    q.pop();
                }
            }
            
            ans = max(ans,i-start+1);
        }
        
        return ans;
    }
};