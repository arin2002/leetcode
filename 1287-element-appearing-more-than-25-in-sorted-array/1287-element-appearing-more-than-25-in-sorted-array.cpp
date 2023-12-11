class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 1, n = arr.size(), prev = arr[0];
        int size = n/4;
        
        for(int i = 0; i<n && (i+size)<n; i++){
            if(arr[i] == arr[i+size]){
                return arr[i];
            }
        }
        
        return arr[n-1];
    }
};