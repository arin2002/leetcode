//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string up = "", down = "";
        
        for(auto it : str){
            if(it >= 'a' && it <= 'z')
                down+=it;
            
            else
                up += it;
        }
        
        sort(up.begin(),up.end());
        sort(down.begin(),down.end());
        
        int p = up.size(), q = down.size();
        int i = 0,  j = 0, k = 0;
        
        while(i<p || j<q && k<n){
            if(str[k] >= 'a' && str[k] <= 'z')
                str[k] = down[j++];
            
            else
                str[k] = up[i++];
            
            k++;
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends