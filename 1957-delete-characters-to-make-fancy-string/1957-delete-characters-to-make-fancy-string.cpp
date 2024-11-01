class Solution {
public:
    string makeFancyString(string s) {
        int cnt =0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            cnt++;
            if(cnt < 3) ans+=s[i];
            if(s[i] != s[i+1]) cnt=0;
        }
        return ans;
    }
};
