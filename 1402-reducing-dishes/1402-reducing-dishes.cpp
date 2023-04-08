class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        
        int n = satisfaction.size();
        int suffix_sum = 0, start = -1;
        for(int i = n-1; i>=0; i--){
            suffix_sum += satisfaction[i];
            
            // cout<<suffix_sum;
            if(suffix_sum < 0)
                break;
            
            start = i;
        }
        
        if(start == -1)
            return 0;
        
        int time = 1, ans = 0;
        for(int i = start; i<n; i++){
            ans += satisfaction[i]*time;
            time++;
        }
        
        return ans;
    }
};