class Solution {
public:
    
    string f(string &ans){
        string invert = "";
        
        for(auto it : ans){
            if(it == '0')
                invert += '1';
            else
                invert += '0';
        }
        
        reverse(invert.begin(),invert.end());
        return invert;
    }
    
    char findKthBit(int n, int k) {
        string ans = "0";
        
        while(--n){
            ans = ans + "1" + f(ans);
        }
        
        return ans[k-1];
    }
};