class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int> > arr(n+1, vector<int> (target+1, 0));
        for(int i = 1; i <= k and i <= target; i++)
            arr[1][i] = 1;

        int sum;
        for(int i = 2; i <= n; i++){
            for(int j = i; j <= target; j++){
                sum = 0;
                for(int l = j-1; l >= j-k and l >= 0; l--)
                    sum = (sum + arr[i-1][l])%1000000007;
                arr[i][j] = sum;
            }
        }

        return arr[n][target];
    }
};
