//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}
// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    // Your code here
    
    vector<int> digit;
    while(n){
        digit.push_back(n%10);
        n/=10;
    }
    
    n = digit.size();
    
    int num = 0;
    for(int i = n-1; i>=0; i--){
        
        if(digit[i] == 0){
            num = num*10 + 5;
        }
        else{
            num = num*10 + digit[i];
        }
    }
    
    return num;
}