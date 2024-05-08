class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        int maxi = *max_element(score.begin(),score.end());
        vector<int> freq(maxi+1,-1);
        
        for(int i = 0; i<n; i++){
            freq[score[i]] = i; 
        }
                
        vector<string> ans(n);
        int cnt = 1;
        
        for(int i = maxi; i>=0; i--){
            if(freq[i] == -1)
                continue;
            
            string num = to_string(cnt);
            
            if(cnt == 1){
                num = "Gold Medal";
            }
            else if(cnt == 2){
                num = "Silver Medal";
            }
            else if(cnt == 3){
                num = "Bronze Medal";
            }
            
            ans[freq[i]] = num;
            cnt++;
        }
        
        return ans;
    }
};