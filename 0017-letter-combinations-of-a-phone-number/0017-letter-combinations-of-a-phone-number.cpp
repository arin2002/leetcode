class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> map{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n = digits.size();
        string temp= "";
        
        function<void(int)>solve = [&](int ind)->void{
            if(ind == n){
                if(temp.size()>0)
                    ans.push_back(temp);
                return;
            }
            
            string s = map[digits[ind]-'0'];
            for(int i = 0; i<s.size(); i++){
                temp += s[i];
                solve(ind+1);
                temp.pop_back();
            }
        };
        
        solve(0);
        return ans;
    }
};