//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isPossible(int a[], int n, int m, int k){
        int studentCounter = 1, pageCount = 0;
        
        for(int i = 0; i<n; i++){
            if(pageCount + a[i] <= k){
                pageCount += a[i];
            }
            else{
                studentCounter++;
                if(studentCounter > m || a[i]>k)
                    return false;
                
                pageCount = a[i];
            }
            
            // if(pageCount > k){
            //     studentCounter++;
            //     pageCount = a[i];
            // }
            
            // if(studentCounter > m)
            //     return false;
        }
        
        return true;
    }
    
    
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) {
        int sum = 0, ans = -1;
        
        if(m>n)
            return -1;
        
        for(int i = 0; i<n; i++)
            sum += a[i];
            
        
        int l = 0, r = sum;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(isPossible(a,n,m,mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends