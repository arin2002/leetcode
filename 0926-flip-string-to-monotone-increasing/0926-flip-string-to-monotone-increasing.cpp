class Solution {
public:
    
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        
        int i = 0, count1 = 0, count2 = 0;
        while(i<n && s[i] != '1')
            i++;
        
        
        for(; i<n; i++){
            if(s[i] == '1'){
                count1++;
            }
            else
                count2++;
            
            count2 = min(count1,count2);
        }
        
        return count2;
    }
};