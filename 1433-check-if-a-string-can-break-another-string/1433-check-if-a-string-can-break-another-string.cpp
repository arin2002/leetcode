class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int count1  = 0, count2 = 0;
        
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        int n = s1.size();
        
        for(int i = 0; i<n; i++){
            if(s1[i] >= s2[i]){
                count1++;
            }
        }
            
        for(int i = 0; i<n; i++){
            if(s1[i] <= s2[i]){
                count2++;
            }
        }
        
        int ans = max(count1,count2);
        
        return ans == n;
    }
};