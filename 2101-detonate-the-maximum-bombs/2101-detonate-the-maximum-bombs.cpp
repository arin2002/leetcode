class Solution {
    #define ll long long int
public:
void dfs(int node,vector<int>adj[],vector<int>&vis,int &c)
{
    c++;
    vis[node]=1;
    for(auto it:adj[node])
    if(!vis[it])
    dfs(it,adj,vis,c);
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int>adj[n+1];
        for(int i=0;i<n;i++)
        {
            ll x1,y1,r1;
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                     ll x2,y2,r2;
                     x2=abs(x1-bombs[j][0]);
                     y2=abs(y1-bombs[j][1]);
                    if(x2*x2+y2*y2<=r1*r1)
                    {
                        adj[i].push_back(j);
                    }
                }
            }
        }
            int maxi=0;
           
             for(int i=0;i<n;i++)
             { 
                 int c=0;
                  vector<int>vis(n,0);
                 dfs(i,adj,vis,c);
                 if(c>maxi)
                 {
                     maxi=c;
                     
                 }
                   
             }
             
             return maxi;
    }
};
