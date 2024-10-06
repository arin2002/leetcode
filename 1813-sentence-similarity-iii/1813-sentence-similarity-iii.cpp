class Solution {
public:
    int dp[101][101][2][2];
    vector<string> split(string& sentence) {
        vector<string> result;
        istringstream stream(sentence);
        string word;

        // Extract each word from the sentence and store it in the result vector
        while (stream >> word) {
            result.push_back(word);
        }

        return result;
    }
    bool solve(vector<string>&s1, vector<string>&s2, int i, int j, int t, int g)
    {
        if(j==s2.size() && i==s1.size()) return true;
        if(j==s2.size() && i!=s1.size())
        {
            return !(t==1);
        }
        if(i==s1.size()) return false;
        
        
        if(dp[i][j][t][g]!=-1) return dp[i][j][t][g]==1;
        
        bool ans=false;
        // ignore when we ignore for first segment we mark t=1 and g=0 means current segment is going on  g=1 means one permissible segment we have already selected
        if(g==0 || t==0)
        ans= solve(s1,s2,i+1,j,1,0); // g==0 keep ignoring 
        
        // use it
        if(s1[i]==s2[j]) 
        {
            if(t==1) g=1; // once if we start using if previously we have ignored then we can't do it anymore so mark g=1
            ans= ans or solve(s1,s2,i+1, j+1,t,g);
        }
        
        return  dp[i][j][t][g]=ans?1:0;
        
    }
    bool areSentencesSimilar(string se1, string se2) {
        
        auto s1=split(se1);
        auto s2=split(se2);
        
        if(s1.size()==s2.size())
        {
            if(s1==s2) return true;
            return false;
        }
        if(s1.size()<s2.size()) swap(s1,s2);
        
        // for(auto i: s1) cout<<i<<" ";cout<<endl;
        // for(auto i: s2) cout<<i<<" "; cout<<endl;
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0,0,0);        
    }
};