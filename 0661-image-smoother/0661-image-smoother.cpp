class Solution {
public:
int fun(int row,int col,vector<vector<int>>& img)
{
    int sum=0;
    int count=0;
    int n=img.size();
    int m=img[0].size();
    for(int delrow=-1;delrow<=1;delrow++)
    {
        for(int delcol=-1;delcol<=1;delcol++)
        {
            int nrow=row+delrow;
            int ncol=col+delcol;
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0)
            {
               sum+=img[nrow][ncol];
               count++;
            }
        }
    }
    return sum/count;
}
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               ans[i][j]=fun(i,j,img);
            }
        }
        return ans;
    }
};
