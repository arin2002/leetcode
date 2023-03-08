//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> ans;
            
            int i = 0, j = 0, k = 0;
            int prev1 = -1, prev2 = -1, prev3 = -1;
            while(i<n1 && j<n2 && k<n3){
                
                while(i<n1 && prev1 == a[i])
                    i++;
                    
                while(j<n2 && prev2 == b[j])
                    j++;
                
                while(k<n3 && prev3 == c[k])
                    k++;
                
                
                if(i>=n1  || j>=n2 || k>=n3)
                    break;
                
                if(a[i] == b[j] && b[j]==c[k]){
                    ans.push_back(a[i]);
                    prev3 = prev2 = prev1 = a[i];
                    i++;j++;k++;
                }
                else if(a[i]<b[j]){
                    prev1 = a[i];
                    i++;
                }
                else if(b[j]<c[k]){
                    prev2 = b[j];
                    j++;
                }
                else{
                    prev3 = c[k];
                    k++;
                }
            }
            
            if(ans.size() == 0)
                return {-1};
            return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends