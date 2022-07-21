class Solution {
public:
    int findMin(vector<int>& arr) {
        
        int n = arr.size();
        
        int low = 0, high = n-1;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int prev = (mid+n-1)%n;
            int next = (mid+1)%n;
            
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next])
                return arr[mid];
            
            else if(arr[mid] <= arr[high])
                high = mid-1;
            else
                low = mid+1;
        }
        
        return 0;
    }
};