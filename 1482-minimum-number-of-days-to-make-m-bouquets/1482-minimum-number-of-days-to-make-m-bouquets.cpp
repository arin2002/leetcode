class Solution {
public:
    bool possible(vector<int> &bloomDay, int days, int k, int m){
        int count = 0, ans = 0;
        for(auto x : bloomDay){
            if(x <= days){
                count++;
            }else{
                count = 0;
            }
            if(count >= k){
                ans++;
                count = count - k;
            }
        }
        return (ans >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        int start = 0, end = 1e9, ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(possible(bloomDay, mid, k, m)){
                ans = mid;
                end = mid - 1;
            }else start = mid + 1;
        }
        return ans;
    }
};
