class Solution {
public:
    
    int ans = 1;
    
    bool isPalind(string &x, string &y){
        int i = 0, j = x.size()-1;
        
        while(i<=j){
            if(x[i] != x[j])
                return false;
            i++; j--;
        }
        
        i = 0; j = y.size()-1;
        while(i<j){
            if(y[i] != y[j])
                return false;
            
            i++; j--;
        }
        
//         set<char> s(x.begin(),x.end());
        
//         for(auto &it: y){
//             if(s.find(it) != s.end())
//                 return false;
//         }
        
        return true;
    }
    
    void solve(int ind, string &x, string &y, string&s){
        if(isPalind(x,y)){
                ans = max(ans,(int)x.size()*(int)y.size());
        }
        
        if(ind>=s.size()){
            return;
        }
        
        //take for x
        x.push_back(s[ind]);
        solve(ind+1,x,y,s);
        x.pop_back();
        
        //take for y
        y.push_back(s[ind]);
        solve(ind+1,x,y,s);
        y.pop_back();
        
        //ignore
        solve(ind+1,x,y,s);
    }
    
    int maxProduct(string s) {
        string x,y;
        solve(0,x,y,s);
        return ans;
    }
};