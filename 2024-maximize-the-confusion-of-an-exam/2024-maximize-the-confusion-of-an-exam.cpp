class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size(), start = 0;
        int ans = 0, K = k;
        
        for(int i = 0; i<n; i++){
            if(s[i]== 'T' || (s[i] == 'F' && k--)){
                ans = max(ans,i-start+1);
                
            }
            
            while(k<0){
                if(s[start++] == 'F')
                    k++;
            }
        }
        
        k = K;
        start = 0;
        for(int i = 0; i<n; i++){
            if(s[i]== 'F' || (s[i] == 'T' && k--)){
                ans = max(ans,i-start+1);
            }
            
            while(k<0){
                if(s[start++] == 'T')
                    k++;
            }
        }
        
        return ans;
    }
};