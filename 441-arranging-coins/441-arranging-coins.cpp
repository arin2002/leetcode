class Solution {
public:
    int arrangeCoins(int n) {
//         int i = 0, j = n;
        
//         long long ans = 0;
//         while(i<=j)
//         {
//             long long mid = i + (j-i)/2;
            
//             long long temp = (mid*(mid+1))/2;
            
//             if(temp <=n){
//                 ans = max(ans,mid);
//                 i = mid+1;
//             }
            
//             else//(temp > n)
//                 j = mid - 1;
//         }
        
//         return ans;
        
        // return sqrt((2*(long)n)+1/4)-1/2;
        return sqrt(2l*n + .25) - .5;
    }
};