class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {    
        int l = 0, r = arr.size()-1;
        
        while(r-l>=k){
            if(abs(x-arr[l]) <= abs(arr[r]-x))
                r--;
            else
                l++;
        }
        return vector<int>(begin(arr) + l, begin(arr) + r + 1);
    }
};