//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int a[], int n, int x)
    {
        //Your Code Here
        sort(a , a+n);
        for(int i = 0; i<n; i++){
            if(i>0 && a[i] == a[i-1])
                continue;
            
            int low = i+1, high = n-1;
            
            while(low<high){
                int sum = a[low]+a[high]+a[i];
                
                if(sum>x){
                    high--;
                }
                else if(sum<x){
                    low++;
                }
                else{
                    return true;
                }
            }
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends