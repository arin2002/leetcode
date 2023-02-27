class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        
        char start = s[0], end = s[3];
        int num1 = s[1], num2 = s[4];
        
        // cout<<num1<<" "<<num2;
        for(;start<=end; start++){
            for(int i = num1; i<=num2; i++){
                string str = "";
                str += start;
                str += i;
                ans.push_back(str);
            }
        }
        
        return ans;
    }
};