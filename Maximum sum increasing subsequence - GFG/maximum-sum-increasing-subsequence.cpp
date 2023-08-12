//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int nums[], int n){
	    
	    vector<vector<int>> dp(n,vector<int>(n+1,-1));
	    
	    function<int(int,int)> solve = [&](int ind, int prev){
	        if(ind == n){
	            return 0;
	        }
	        
	        if(dp[ind][prev+1] != -1)
	            return dp[ind][prev+1];
	        
	        int l = INT_MIN;
	        
	        if(prev == -1 || nums[ind] > nums[prev]){
	            l = nums[ind]+solve(ind+1,ind);
	        }
	        
	        int r = solve(ind+1,prev);
	        
	        return dp[ind][prev+1] = max(l,r);
	    };
	    
	    return solve(0,-1);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends