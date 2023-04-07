//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    int n;
    void solve(int i, int j, string temp, vector<vector<int>> nums){
        if(i<0 || i>=n || j<0 || j>=n || nums[i][j] == 0)
            return;
            
        if(i == n-1 && j == n-1){
            ans.push_back(temp);
            return;
        }
        
        nums[i][j] = 0;
        solve(i+1,j,temp+"D",nums);
        solve(i,j+1,temp+"R",nums);
        solve(i-1,j,temp+"U",nums);
        solve(i,j-1,temp+"L",nums);
    }
    
    vector<string> findPath(vector<vector<int>> nums, int n) {
        // Your code goes here
        this->n = n;
        solve(0,0,"",nums);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends