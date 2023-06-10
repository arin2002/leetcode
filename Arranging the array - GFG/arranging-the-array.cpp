//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int s[], int n)
        {
            // Your code goes here
            vector<int> pos,neg;
            
            for(int i = 0; i<n; i++){
                if(s[i]<0){
                    neg.push_back(s[i]);
                }
                else{
                    pos.push_back(s[i]);
                }
            }
            
            int i = 0;
            for(auto it: neg){
                s[i++] = it;
            }
            
            for(auto &it: pos){
                s[i++] = it;
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends