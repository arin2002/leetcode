class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int>v(1025,0);
        v[0]=1;
        long long mask=0,ans=0;
        for(auto i: word){
            mask^=(1<<(i-'a'));
            ans+=v[mask];
            for(long long j=0;j<10;j++) ans+=v[((1LL<<j)^mask)];
            v[mask]++;
        }
        return ans;
    }
};
