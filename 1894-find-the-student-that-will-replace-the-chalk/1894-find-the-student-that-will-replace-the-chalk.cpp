class Solution {
public:
    int chalkReplacer(vector<int>& chalk, long k) {

        long long sum = 0;
        for(long i=0;i<chalk.size();i++){
            sum += chalk[i];
        }

        long long res = k % sum;
        
        for(int i=0;i<chalk.size();i++){
            if(res < chalk[i]){
                return i;
            }
            res -= chalk[i];
        }
        return -1;
    }
};
