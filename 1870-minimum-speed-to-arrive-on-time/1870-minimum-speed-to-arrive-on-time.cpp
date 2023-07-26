class Solution {
public:
    double h;
    
    bool solve(double speed, vector<int> &dist){
        double total = 0;
        int n = dist.size();
        for(int i = 0; i<n-1; i++){
            double d = ceil(dist[i]/speed);
            total += d;
        }
        total += (double)dist[n-1]/(double)speed;
        cout<<total<<" "<<speed<<endl;
        return total <= h;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans = -1;
        int l = 1, r = 1e8;
        h = hour;
        
        while(l<=r){
            
            int mid = l +(r-l)/2;
            
            if(solve(mid,dist)){
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