class Solution {
public:
    
    bool TimeEnough(long long time, long long totalTrips, vector<int> &nums){
        long long total = 0;
        
        for(auto &it : nums){
            long long val = it;
            total += (time/val);
        }
        
        return total >= totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 1LL * *min_element(time.begin(), time.end()) * totalTrips;
        
        while(l<r){
            long long mid = l+(r-l)/2;
            
            if(TimeEnough(mid,totalTrips,time)){
                r = mid;
            }
            else
                l = mid+1;
        }
        
        return l;
    }
};