class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0, j = arr.size()-1, mid;
        
        // sorted h pehle he
        // if((arr[j]-(j+1)) == 0)
        //     return arr[j]+k;
        
        // finding vohi sorted wal
        while(i<=j){
            
            mid = (i+j)/2;
            int expected = (arr[mid]-(mid+1));
            
            if(expected<k){
                i = mid+1;
            }
            else
                j = mid-1;
        }
        
        // cout<<j<<endl;
        // if(j>= 0)
        //     return arr[j]+k-(arr[j]-(j+1));
        
        return i+k;
    }
};