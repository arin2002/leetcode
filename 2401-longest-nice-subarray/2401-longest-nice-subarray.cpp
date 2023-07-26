class Solution {
public:
    
    void add(int n, vector<int> &freq){
        // add set bits
        for(int i = 0; i<31; i++){
            int set = n&(1<<i);
            if(set){
                freq[i]++;
            }
        }
    }
    
    void remove(int n, vector<int> &freq){
        // add set bits
        for(int i = 0; i<31; i++){
            int set = n&(1<<i);
            if(set){
                freq[i]--;
            }
        }
    }
    
    bool check(vector<int> &freq){
        for(int i = 0; i<31; i++){
            if(freq[i]>1){
                return true;
            }
        }
        
        return false;
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0, start = 0;
        int n = nums.size();
        vector<int> freq(32);
        
        for(int i = 0; i<n; i++){
            add(nums[i],freq);
            
            while(check(freq)){
                remove(nums[start++],freq);
            }
            
            ans = max(ans,i-start+1);
        }
        
        return ans;
        
    
    }
};



















