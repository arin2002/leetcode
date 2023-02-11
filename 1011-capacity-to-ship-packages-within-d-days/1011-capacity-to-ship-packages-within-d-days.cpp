class Solution {
public:
    
    bool possible(vector<int>& weights, int days, int max){
        int daysCount = 1, weightCount = 0;
        
        for(auto it : weights){
            if(it + weightCount <= max){
                weightCount += it;
            }
            else{
                daysCount++;
                if(days < daysCount || it > max)
                    return false;
                
                weightCount = it;
            }
        }
        
        return true;
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r= 0, ans = -1;
        
        for(auto it : weights)
            r += it;
        
        
        while(l<=r){
            
            int mid = l + (r-l)/2;
            
            if(possible(weights,days,mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        return ans;
    }
};