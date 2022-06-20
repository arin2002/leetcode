class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 1,temp;
        
        for(int i = 0; i<n;i++)
        {
            temp = start + 2 * i;
            
            if(i == 0)
                ans = temp;
            else{
                ans ^=temp;
            }
        }
        
        return ans;
    }
};