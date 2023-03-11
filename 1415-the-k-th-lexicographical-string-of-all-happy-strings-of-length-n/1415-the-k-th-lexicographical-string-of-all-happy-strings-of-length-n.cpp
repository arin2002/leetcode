class Solution {
public:
    
    string ans = "";
    
    void solve(string temp, int &k, int n, string &s){
        
        if(k == 0){
            return;
        }
        
        if(temp.size() == n){
            ans = temp;
            k--;
            return;
        }
        
        for(int i = 0; i<3; i++){
            if(temp.size() == 0 || temp[temp.size()-1] != s[i])
                solve(temp+s[i],k,n,s);
        }
    }
    
    string getHappyString(int n, int k) {
        string s = "abc";
        
        solve("",k,n,s);
        
        if(k!=0)
            return "";
        
        return ans;
    }
};