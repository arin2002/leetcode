class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int n = satisfaction.size(), ans = 0;
        int suffixSum = 0;
        
        int start = n-1, time = 1;
        
        // find the point till we get sum >= 0
        // uske baad he apna aayea max
        // kyuki uske baad to min ho jayega
        for(int i = n-1; i>=0; i--){
            suffixSum += satisfaction[i];
            
            if(suffixSum<0)
                break;
            
            start--;
        }
        
        start++;
        
        for(int i = start; i<n; i++){
            ans += satisfaction[i]*time;
            time++;
        }
        return ans;
    }
};