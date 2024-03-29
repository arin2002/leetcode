// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> ans;
    
    void sums(int i,vector<int> nums,int n,int sumss){
        if(i >= n){
            ans.push_back(sumss);
            return;
        }
        
        sums(i+1,nums,n,sumss+nums[i]);
        //sum-=nums[i];
        sums(i+1,nums,n,sumss);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        sums(0,arr,N,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends