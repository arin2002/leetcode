class Solution {
public:
    bool dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>& mat)
    {
        vis[r][c]=1;
        if(r==mat.size()-1)return true;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        bool ans = false;
        for(int j=0;j<4;j++)
        {
            int nr=dr[j]+r;
            int nc = dc[j]+c;
            if(nr>=0 and nr<mat.size() and nc>=0 and nc<mat[0].size() and mat[nr][nc]==0 and vis[nr][nc]==0)
            {
                ans|=dfs(nr,nc,vis,mat);
                if(ans==true)return true;
            }
        }
        return ans;
        
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int l=1,h=cells.size()-1;
        int res=0;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            vector<vector<int>> days(row,vector<int> (col,0));
            for(int i=0;i<=m;i++)
            {
                days[cells[i][0]-1][cells[i][1]-1]=1;
            }
            vector<vector<int>> vis(row,vector<int> (col,0));
            bool ans=false;
            for(int j=0;j<col;j++)
            {
                if(vis[0][j]==0 and days[0][j]==0)
                    ans |= dfs(0,j,vis,days);
            }
            if(ans==true)
            {
                res=m;
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
        return l;
    }
};
