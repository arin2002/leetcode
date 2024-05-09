class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0, n = happiness.size();
        int cnt = 0;
        // priority_queue<int> pq(happiness.begin(),happiness.end());
        sort(happiness.begin(),happiness.end(), greater<int>());
        
        for(int i = 0; i<n; i++){
            if(k == 0 || happiness[i]-cnt <= 0)
                break;
            
            ans += (long long)(happiness[i]-cnt);
            k--;
            cnt++;
        }
        
        return ans;
    }
};