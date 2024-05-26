class Solution {
public:
    int checkRecord(int n) {
        long long m = 1e9+7;
        long long p = 1;
        long long l = 1,preP = 1;
        long long pA = 0,lA = 0,prePa=  0,a = 1,preA = 0;
        for(int i = 1;i<n;i++){
            long long newP = (p + l) % m;
            long long newL = (p +  preP) % m;

            long long newPa = (pA + lA + a) % m;
            long long newLa = (pA + a + prePa + preA) % m;
            long long newA = (p + l) % m;

            preP = p;
            p = newP;
            l = newL;

            preA = a;
            a = newA;
            prePa = pA;
            pA = newPa;
            lA = newLa;
        }
        long long ans = (l + p + a + pA + lA) % m;
        return (int)ans;
    }
};
