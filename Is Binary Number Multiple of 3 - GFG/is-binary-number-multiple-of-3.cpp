//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    long long num = 0, c = 1;
	    for(int i = s.size()-1; i>=0; i--){
	        if(s[i] == '1'){
	            num = (num%3+c%3)%3; 
	        }
	        c = (c%3*2%3)%3;
	    }
	    
	    return num%3 == 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends