class Solution {
public:
    
    bool cmp(string &s, vector<int> &v){
        vector<int> self(26,0);
        
        for(int i = 0; i<s.length(); i++){
            if(self[s[i]-'a'] == 1)
                return true;
            
            self[s[i]-'a'] = 1;
        }
        
        for(auto i : s){
            if(v[i-'a'] == 1)
                return true;
        }
        
        return false;
    }
    
    
    int f(int i, vector<string> &nums, vector<int> v, int len){
        if(i<0)
            return len;
        
        string s = nums[i];
        if(cmp(nums[i],v))
            return f(i-1,nums,v,len);
        
        for(auto j : s){
            v[j-'a'] = 1;
        }
        
        //pick
        len += s.size();
        int l = f(i-1,nums,v,len);
        
        for(auto j : s){
            v[j-'a'] = 0;
        }
        
        len -= s.size();
        
        int r = f(i-1,nums,v,len);
        
        return max(l,r);
    }
    
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        
        vector<int> v(26,0);
        return f(n-1,arr,v,0);
    }
};