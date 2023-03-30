class Solution {
public:
    
    unordered_map<string,bool> ump;
    
    bool isScramble(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        if(n!=m)
            return false;
        
        if(s1 == s2)
            return true;
        
        if(n == 1)
            return false;
        
        string s = s1 + "." + s2;
        
        if(ump.find(s) != ump.end())
            return ump[s];
        
        for(int i = 1; i<n; i++){
            // swaps
            string left1 = s1.substr(0,i);
            string left2 = s2.substr(n-i);
            
            string right1 = s1.substr(i);
            string right2 = s2.substr(0,n-i);
            
            bool swaps = isScramble(left1,left2) && isScramble(right1,right2);
            
            
            if(swaps)
                return ump[s] = true;
            
            //no swaps;
            left1 = s1.substr(0,i);
            left2 = s2.substr(0,i);
            
            right1 = s1.substr(i);
            right2 = s2.substr(i);
            
            bool no_swaps = isScramble(left1,left2) && isScramble(right1, right2);
            
            if(no_swaps)
                return ump[s] = true;
        }
        
        return ump[s] = false;
    }
};