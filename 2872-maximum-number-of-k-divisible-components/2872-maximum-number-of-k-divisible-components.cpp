class Solution {
public:
    int ans = 0;
    int dfs(vector<vector<int>>& tree,vector<int>& values, int cur,int parent,int k){
        int total = values[cur];
        
        for(int child : tree[cur]){
            if(child != parent)
                total += dfs(tree, values, child, cur, k);
           
        }
        
         if(total % k == 0)
                ans++;
        
        return total % k;
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>> tree(n);
        
        for(vector<int> edge : edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        dfs(tree, values, 0, -1, k);
        
        return ans;
    }
};
