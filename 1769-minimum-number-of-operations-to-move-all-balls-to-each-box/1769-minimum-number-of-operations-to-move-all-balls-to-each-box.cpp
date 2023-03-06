class Solution {
public:
    
    int solve(int i, string &s){
        
        int count = 0;
        for(int j = 0; j<s.size(); j++){
            if(s[j] == '1')
                count += abs(j-i);
        }
        
        return count;
    }
    
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        
        for(int i = 0; i<boxes.size(); i++){
            ans[i] = solve(i,boxes);
        }
        
        return ans;
    }
};