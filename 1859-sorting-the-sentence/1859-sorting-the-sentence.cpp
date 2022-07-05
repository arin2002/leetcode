class Solution {
public:
    string sortSentence(string s) {
        vector<string>v(10,"0");
        int n = s.length(), j =0;
        string ans="";
        
        for(int i =0; i<n; i++)
        {
            if(s[i]>='1' && s[i]<='9')
            {
                int a = s[i]-'0';
                j = max(a,j);
                v[a] = ans;
                ans="";
            }
            else if(s[i]>='A' && s[i]<='Z'|| s[i]>='a' && s[i]<='z')
                ans+=s[i];
        }
        ans="";
        for(int i =1; i<=j;i++)
        {
            if(v[i] != "0")
            {
                cout<<v[i];
                ans+=v[i];
                
                if(i!=j)
                ans+=" ";
            }
        }
        return ans;
    }
};