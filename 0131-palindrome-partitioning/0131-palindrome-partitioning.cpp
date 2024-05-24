class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.size();
        vector<string> temp;
        
        function<void(int)> solve = [&](int ind){
            if(ind >= n){
                int flag = 1, m = temp.size();
                
                for(auto &it: temp){
                    string st = it;
                    reverse(st.begin(),st.end());
                    
                    if(st != it){
                        flag = 0;
                        break;
                    }
                }
                
                if(flag == 0 ||  m == 0)
                    return;
                
                ans.push_back(temp);
                return;
            }
            
            string t;
            for(int i = ind; i<n; i++){
                t += s[i];
                temp.push_back(t);
                solve(i+1);
                temp.pop_back();
            }
        };
        
        solve(0);
        return ans;
    }
};