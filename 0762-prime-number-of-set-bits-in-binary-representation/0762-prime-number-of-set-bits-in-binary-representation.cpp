class Solution {
public:
    bool isprime(int num)
    {
        if (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num == 19 || num == 23) return 1;
        return 0;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            int x=__builtin_popcount (i);
            if(isprime(x) && x!=1)
                ans++;
        }
        return ans;
    }
};
