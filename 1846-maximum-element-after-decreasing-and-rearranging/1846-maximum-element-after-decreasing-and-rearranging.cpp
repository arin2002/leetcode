class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        arr[0] = 1;
        int maxi = arr[0];
        
        for(int i = 1; i<n; i++){
            int diff = abs(arr[i]-arr[i-1]);
            
            if(diff > 1){
                if(arr[i] > arr[i-1]){
                    arr[i] = arr[i-1]+1;
                }
                else{
                    arr[i-1] = arr[i]+1;
                }
            }
            
            // maxi = max({arr[i],maxi,arr[i-1]});
        }
        
        maxi = *max_element(arr.begin(),arr.end());
        return maxi;
    }
};