class Solution {
public:
int n;
vector<int>parent;
vector<int>rank;
int find(vector<int>&parent,int x){
    if(x==parent[x]) return x;
    return parent[x]=find(parent,parent[x]);
}
void Union(int x,int y)
{
    int px=find(parent,x);
    int py=find(parent,y);
    if(px==py) return;
    if(rank[px]>rank[py])
    {
        parent[py]=px;
    }
    else if(rank[px]<rank[py])
    {
        parent[px]=py;
    }
    else{
        parent[py]=px;
        rank[px]++;
    }
}
    int removeStones(vector<vector<int>>& stones) {
        n=stones.size();
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    Union(i,j);
                }
            }
        }
        int groups=0;
        for(int i=0;i<n;i++)
        {
            if(i==parent[i]) groups++;
        }
        return n-groups;
    }
};