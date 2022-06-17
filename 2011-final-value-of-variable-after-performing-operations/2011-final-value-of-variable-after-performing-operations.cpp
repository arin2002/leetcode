class Solution {
public:
    int finalValueAfterOperations(vector<string>& nums) {
        
        int n = nums.size();
        int x = 0;
        for(int i = 0; i<n; i++)
        {
            int k = 0;
            string s =  nums[i];
            
            while(s[k] == 'X'){k++;}
            
            if(s[k] == '-')
                x--;
            else
                x++;
        }
        
        return x;
    }
};