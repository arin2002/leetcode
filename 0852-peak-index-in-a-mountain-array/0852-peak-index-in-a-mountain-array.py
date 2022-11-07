class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0, j = arr.size()-1, mid = -1;
        
        while(i<j){
            mid = i + (j-i)/2;
            
            if(arr[mid]<arr[mid+1])
                i = mid+1;
            else
                j = mid;
        }
        
        return i;
    }
};