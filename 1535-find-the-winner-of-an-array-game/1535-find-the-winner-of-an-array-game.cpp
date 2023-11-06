class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int count = 0, prev = -1;
        int n = arr.size();
        
        // main logic
        // if(k >= n){
        //     return *max_element(arr.begin(),arr.end());
        // }
        
        for(int i = 1; i<n; i++){
            
            if(arr[0]<arr[i]){
                arr[0] = arr[i];
            }
                        
            if(prev == arr[0]){
                count++;
            }
            else{
                prev = arr[0];
                count = 1;
            }
            
            if(count == k){
                return arr[0];
            }
        }
        
        return arr[0];
    }
};