class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt=0,ones=0;
        for(long long i=0;i<s.length();i++){
            if(s[i]=='0' and ones) cnt+=ones;
            else if(s[i]=='1') ones++;
        }
        return cnt;
    }
};
