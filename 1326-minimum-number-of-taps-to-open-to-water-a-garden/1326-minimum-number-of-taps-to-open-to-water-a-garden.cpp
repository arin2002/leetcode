class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mini=0;
        int maxi=0;
        int open=0;
        while(maxi<n){
            for(int i=0;i<ranges.size();i++){
                if(i-ranges[i]<=mini && i+ranges[i]>maxi){
                    maxi=i+ranges[i];
                }
            }
            if(mini ==maxi) return -1;
            open++;
            mini=maxi;
        }
        return open;
    }
};
