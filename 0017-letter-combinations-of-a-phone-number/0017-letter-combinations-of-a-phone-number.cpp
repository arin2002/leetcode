class Solution {
public:
    
    vector<string> ans,map;
    
    void solve(int ind, string temp,string &digits){
        if(ind >= digits.size()){
            if(temp.size() != 0)
                ans.push_back(temp);
            
            return;
        }
        
        int n = digits[ind]-'0';
        string s = map[n];
        
        for(int i = 0; i<s.size(); i++){
            temp.push_back(s[i]);
            solve(ind+1,temp,digits);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string &digits) {
        map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(0,"",digits);
        return ans;
    }
};