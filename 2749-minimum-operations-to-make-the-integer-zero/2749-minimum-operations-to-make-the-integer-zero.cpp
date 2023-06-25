class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long x = num1;
        for(int i=1;i<=59;i++){
            x -= num2;
            if(x < 0) return -1;
            int cnt = 0,c = 0;
            for(int j=0;j<59;j++){
                if(x>>j&1){
                    cnt += j + 1;
                    ++c;
                }
            }
            if(cnt >= i && i >= c) return i;
        }
        return -1;
    }
};
