//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxLength(string s)
    {
        // code here
        int n = s.size();
        vector<int> temp;
        temp.push_back(s[0]);
        
        
        for(int i = 1; i<n; i++){
            if(s[i]>temp.back()){
                temp.push_back(s[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),s[i])-temp.begin();
                temp[ind] = s[i];
            }
        }
        
        return temp.size();
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0; 
}
// } Driver Code Ends