class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        int n = arr.size();
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            int sum = 0, size = 0;
            for(int j = i; j<n; j++){
                sum+=arr[j];
                size++;
                if(size%2 !=0)
                    ans+=sum;
            }
        }        
        return ans;
    }
};