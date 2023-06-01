class Solution {
public:
    int n,m,x,y;
    vector<vector<int>> vis;
    vector<int> drs = {-1,0,1,0,-1};
    
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& row, vector<int>& col) {
        // queue<pair<int,pair<int,int>>> q;
        // q.push({0,startPos[0],startPos[1]});
        n = row.size(); m = col.size();
        x = homePos[0]; y = homePos[1];
        int sum = 0;
        int i = startPos[0], j = startPos[1];
        
        // reach row
        if(i<x){
            while(i<n && i<x){
                sum += row[++i];
            }
        }
        else{
            while(i<n && i>x){
                sum += row[--i];
            }
        }
        
        if(j<y){
            while(j<m && j<y){
                sum+= col[++j];
            }
        }
        else{
            while(j<m && j>y){
                sum+= col[--j];
            }
        }
        
        return sum;
    }
};