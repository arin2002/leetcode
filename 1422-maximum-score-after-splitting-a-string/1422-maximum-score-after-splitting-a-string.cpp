class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        
        vector<int> left(n);
        left[0] = s[0] == '0' ? 1:0;
        
        for(int i = 1; i<n; i++){
            if(s[i] == '0'){
                left[i] = left[i-1]+1;
            }
            else{
                left[i] = left[i-1];
            }
        }
        
        int count = 0, ans = 0;
        for(int j = n-1; j>=1; j--){
            if(s[j] == '1'){
                count++;
            }
            
            ans = max(ans,left[j-1]+count);
        }
        
        return ans;
    }
};