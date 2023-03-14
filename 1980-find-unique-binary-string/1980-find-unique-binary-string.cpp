class Solution {
public:
    unordered_map<string,int> ump;
    int n;
    string ans;
    
    void solve(string temp){
        if(temp.size() == n ){
            if(ump.find(temp) == ump.end()){
                ans = temp;
            }
            return;
        }
        
        solve(temp+'1');
        solve(temp+'0');
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums[0].size();
        for(auto it : nums)
            ump[it]++;
        
        solve("");
        return ans;
    }
};