class Solution {
public:
    
    bool check(string &s){
        for(auto it : s){
            if(it >= 'a' && it <= 'z')
                return 1;
        }
        
        return 0;
    }
    
    
    int maximumValue(vector<string>& strs) {
        
        int ans = 0;
        for(auto it : strs){
            if(check(it))
                ans = max(ans,(int) it.size());
            
            else
                ans = max(ans,stoi(it));
        }
        
        return ans;
    }
};