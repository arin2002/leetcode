class Solution {
public:
    int minDeletions(string s) {
        // int freq[27] = {0};
        vector<int> freq(26);
        // priority_queue<int,vector<int>,greater<int>> pq;
        // priority_queue<int> pq;
        int ans = 0;
        
        for(auto &it: s){
            freq[it-'a']++;
        }
        
        sort(freq.begin(),freq.end());
        
        for(int i = 24; i>=0; i--){
            if(freq[i] == 0)
                break;
            
            // we are trying to make ascending order
            // so >=  done to make it possible
            if(freq[i] >= freq[i+1]){
                int prev = freq[i];
                freq[i] = max(0, freq[i+1]-1);
                // change
                ans += prev-freq[i];
            }
        }
        
        
        
        return ans;
    }
};