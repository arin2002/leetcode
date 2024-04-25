class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.length();
        vector<int> t(26,0);
        int res=0;
        for(int i=0;i<n;i++){
            int curr=s[i]-'a';
            int l=max(0,curr-k);
            int r=min(25,curr+k);
            int longest=0;
            for(int j=l;j<=r;j++){
                longest=max(longest,t[j]);
            }
            t[curr]=max(t[curr],longest+1);
            res=max(res,t[curr]);
        }
        return res;
    }
};
