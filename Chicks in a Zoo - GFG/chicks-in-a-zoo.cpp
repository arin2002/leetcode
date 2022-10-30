//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
long long int NoOfChicks(int n){
	    vector<long long int>vec(n,0);
        vec[0] = 1;
        long long int dup = 1;
        for(int i=1;i<n;i++){
            if(i>5)
                dup=dup-vec[i-6];
            vec[i]=dup*2;
            dup+=vec[i];
	    }
        return dup;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends