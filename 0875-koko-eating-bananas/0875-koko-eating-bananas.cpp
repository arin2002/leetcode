class Solution {
public:
    
    
    bool canEat(int rate, vector<int> nums, int h){
        int hrs = 0;
        
        for(auto &it: nums){
            if(it<=rate)
                hrs++;
            else if(it%rate == 0)
                hrs += (it/rate);
            else
                hrs += (it/rate)+1;
        }
        
        // cout<<rate<<" "<<hrs<<endl;
        return hrs <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end());
        
        int ans = 0;
        while(l<r){
            
            long mid = (l+r)/2;
            
            if(canEat(mid,piles,h)){
                ans = mid;
                r = mid;
            }
            else
                l = mid+1;
        }
        
        return l;
    }
};