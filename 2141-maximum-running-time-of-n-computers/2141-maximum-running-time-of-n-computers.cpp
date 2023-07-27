class Solution {
public:
    bool isPossible(long long time, int computer, long long totalSum, vector<int>& batteries){

        int n = batteries.size();

        for(int i=n-1;i>=0;i--){

            if(batteries[i] >= time){
                computer--;
                totalSum -= batteries[i];
            }
            else if(computer && (totalSum/computer) >= time) return true;

        }

        return computer <= 0;

    }

    long long maxRunTime(int computer, vector<int>& batteries) {

        sort(batteries.begin(),batteries.end());

        int n = batteries.size();
        long long totalSum = 0;

        for(int i=0;i<n;i++){
            totalSum += batteries[i];
        }

        long long lo = 0 , hi = totalSum;
        long long maxTime = 0;

        while(lo <= hi){

            long long mid = lo + (hi - lo) / 2;

            if(isPossible(mid,computer,totalSum,batteries)){
                maxTime = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return maxTime;
    }
};
