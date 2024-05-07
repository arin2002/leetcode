class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), ans = 0;
        int ans1 = 0, ans2 = 0, f1 = 0;
        // our answer can be in form 0101010101
        // or 101010101010
        
        // so we will compare whichever will give minimum will be returneed
        
        for(auto &it: s){
            int a = it-'0';
            
            if(a != f1)
                ans1++;
            else
                ans2++;
            
            
            // change flag
            f1 = !f1;
        }
        
        return min(ans1,ans2);
    }
};