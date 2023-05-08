//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
            long n = s.size(), num = 0;
            long long pow[100001] = {1};
            
            for(int i = 1; i<=n; i++){
                pow[i] = (pow[i-1]*2)%m;
            }
            
            int k = 0;
            for(int i = n-1; i>=0; i--){
                if(s[i] == '1'){
                    num += pow[k]%m;
                    num = num%m;
                }
                
                num = num%m;
                k++;
            }
            
            return num%m;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends