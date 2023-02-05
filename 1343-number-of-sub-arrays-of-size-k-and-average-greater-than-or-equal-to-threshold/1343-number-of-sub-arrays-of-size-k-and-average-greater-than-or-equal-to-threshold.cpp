class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long sum = 0, i = 0, count = 0;
        
        for(int j = 0; j<arr.size(); j++){
            sum += arr[j];
            
            if(j-i+1 < k)
                continue;
            
            int avg = sum/k;
            if(avg >= threshold)
                count++;
            
            sum -= arr[i];
            i++;
        }
        
        return count;
    }
};