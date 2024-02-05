class Solution {
public:
    
    int firstUniqChar(string s) {
        vector<int> nums(26);
        int n = s.size();
        
        for(int i = n-1; i>=0; i--){            
            nums[s[i]-'a']++;
        }
        
        for(int i = 0; i<n; i++){
            if(nums[s[i]-'a'] == 1)
                return i;
        }
        
        return -1;
    }
};