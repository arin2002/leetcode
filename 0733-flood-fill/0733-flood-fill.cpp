class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>>& image, int col, int ind){
        if(i<0 || j<0 || i>=image.size() || j>= image[0].size() || image[i][j] != ind)
            return;
        
        image[i][j] = col;
        
        dfs(i+1,j,image,col,ind);
        dfs(i,j+1,image,col,ind);
        dfs(i-1,j,image,col,ind);
        dfs(i,j-1,image,col,ind);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;
        
        dfs(sr,sc,image,color,image[sr][sc]);
        
        return image;
    }
};