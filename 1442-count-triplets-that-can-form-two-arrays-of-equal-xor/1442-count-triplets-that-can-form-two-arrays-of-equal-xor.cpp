class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // unordered_map<int,int>mp;
        int n=arr.size();
        int ans=0;
        for(int i=1;i<n;i++){
            arr[i]^=arr[i-1];
            cout<<arr[i]<<" ";
        }cout<<endl;
        for(int i=0;i<n-2;i++){
            for(int j=i+2;j<n;j++){
                if(arr[i]==arr[j]){
                    ans+=(j-i-1);
                }
            }
        }
        for(int i=1;i<n;i++){
            if(arr[i]==0){
                ans+=(i);
            }
        }
        return ans;

    }
};
