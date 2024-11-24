class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        long long ans = 0;
        int negCount = 0;

        for(vector<int> &row : matrix){
            for(int &ele : row){
                ans += abs(ele);

                mini = min(mini,abs(ele));

                if(ele < 0) negCount++;
            }
        }

        if(negCount & 1) return ans - 2*mini;

        return ans;
    }
};
