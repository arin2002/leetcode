class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        int n = dist.size();
        vector<int> time(n);

        for(int i = 0 ; i < n ; i++)
            time[i] = ceil((float)dist[i]/speed[i]);

        sort(time.begin(),time.end());

        for(int i = 0 ; i < n-1 ; i++){
            int gunShot_time = i + 1;
            if(time[i] == time[i+1] && time[i] <= gunShot_time)
               return i + 1;  
        }
        
        return n;
        
    }
};
