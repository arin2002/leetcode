//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int ans = arr[n-1]-arr[0];
        int low, high;
        
        for(int i = 0; i<n-1; i++){
            int a = arr[i], b = arr[i+1];
            
            high = max(arr[n-1]-k,a+k);
            low = min(arr[0]+k,b-k);
            
            if(high < 0 || low<0)
                continue;
            
            // cout<<high<<" "<<low<<endl;
            ans = min(ans,high-low);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends