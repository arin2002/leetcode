class Solution {
public:
    bool checkRecord(string s) {
        
        int count = 0, count1 = 0;
        for(int j = 0; j<s.size(); j++){
            if(s[j] == 'A')
                count++;
            
            if(j<s.size()-2 && s[j] == 'L' && s[j+1] == 'L' && s[j+2] == 'L')
                count1++;
        }
        
        if(count >= 2 || count1)
            return 0;
        
        return 1;
    }
};