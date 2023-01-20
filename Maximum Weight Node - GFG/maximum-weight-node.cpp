//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      vector<int> arr(N);
      int ans = INT_MIN, ind = 0;
      
      for(int i = 0; i<N; i++){
          
          if(Edge[i] == -1)
          continue;
          
          arr[Edge[i]] += i;
          
          if(arr[Edge[i]] >= ans){
              if(arr[Edge[i]] == ans){
                  ind = Edge[i];
              }
              else{
                  ind = Edge[i];
                  ans = arr[Edge[i]];
              }
          }
      }
      
      return ind;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends