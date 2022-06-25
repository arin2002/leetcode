class Solution {
public:
    string toLowerCase(string s) {
        string st = "";
        
        for(auto i : s)
        {
            if(i >='A' && i<='Z')
            {
                i +=32;
            }
            
            st+=i;

        }
        
        return st;
    }
};