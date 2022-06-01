// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> v;
    int count = 0;
    
    void result(int n, int a, int c)
    {
        count+=1;
        
        if(count == n)
        {
            v.push_back(a);
            v.push_back(c);
        }
    }
    
    void hanoi(int N,int n, int a , int b, int c)
    {
        if(N>=1 && count <n)
        {
            hanoi(N-1,n,a,c,b);
            result(n,a,b);
            if(v.size()>1)
            return;
            hanoi(N-1,n,c,b,a);
        }
    }

    vector<int> shiftPile(int N, int n){
        hanoi(N,n,1,3,2);
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends