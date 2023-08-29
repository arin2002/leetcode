class Solution {
public:
    int bestClosingTime(string &s) {
        int n = s.size();  
        int ans = 0, mini = INT_MAX, y = 0, N = 0;
        vector<int> pre(n), suff(n);
        
        for(int i = 0; i<n; i++){            
            if(s[i] == 'N')
                N++;
            
            pre[i] = N;
        }
        
        for(int i = n-1; i>=0; i--){
            if(s[i] == 'Y')
                y++;
            
            suff[i] = y;
        }
        
        for(int i = 0; i<=n; i++){
            int curr = 0;
            
            if(i == 0){
                curr = y;
            }
            else if(i == n){
                curr = N;
            }
            else{
                curr = pre[i-1]+suff[i];
            }
            
            cout<<curr<<endl;
            if(curr <  mini){
                mini = curr;
                ans = i;
            }
        }
        
        cout<<endl;
        return ans;
    }
};