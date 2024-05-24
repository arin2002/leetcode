class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.size();
        vector<string> temp;
        
        auto check = [&](string s){
            int low = 0, high = s.size()-1;
            while(low < high){
                if(s[low++] != s[high--])
                    return false;
            }
            
            return true;
        };
        
        function<void(int)> solve = [&](int ind){
            if(ind >= n){
                ans.push_back(temp);
                return;
            }
            
            string t;
            for(int i = ind; i<n; i++){
                t += s[i];
                temp.push_back(t);
                
                if(check(t))
                    solve(i+1);
                
                temp.pop_back();
            }
        };
        
        solve(0);
        return ans;
    }
};