class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        size_t m = mat.size();
        size_t n = mat[0].size();
        int count{};

        for(int i{}; i < m; i++){
            int sum{};
            int index{};
            for(int j{}; j < n; j++){
                sum += mat[i][j];
                if(mat[i][j] == 1)
                    index = j;
            }
            if(sum == 1){
                int sumCol{};
                for(int k{}; k < m; k++){
                    sumCol += mat[k][index];
                }
                if(sumCol == 1) count++;
            }
        }

        return count;
    }
};
