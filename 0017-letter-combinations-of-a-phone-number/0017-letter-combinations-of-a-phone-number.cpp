class Solution {
public:
    
    vector<string> ans;
    
    void solve(int ind, string map[], string temp, string &digits){
        if(ind >= digits.size()){
            
            if(temp.size() != 0)
            ans.push_back(temp);
            return;
        }
        
        int num = digits[ind]-'0';
        
        string s = map[num];
        for(int i = 0; i<s.size(); i++){
            temp.push_back(s[i]);
            solve(ind+1,map,temp,digits);
            temp.pop_back();
        }
    } 
    
    vector<string> letterCombinations(string &digits) {
        
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(0,map,"",digits);
        
        return ans;
    }
};