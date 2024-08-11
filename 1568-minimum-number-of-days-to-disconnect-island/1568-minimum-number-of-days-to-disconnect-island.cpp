class DSU {
private:
    vector<int> parent;
public:
    vector<int> size;
    int curGrps;
    DSU(int n) {
        parent = vector<int>(n, -1);
        size = vector<int>(n, 0);
        curGrps = 0;
    }
    void reg(int node) {
        curGrps++;
        size[node]++;
    }
    int getParent(int node) {
        if(parent[node] == -1)
            return node;
        int p = getParent(parent[node]);
        parent[node] = p;
        return p;
    }

    void unionSets(int a, int b) {
        int arep = getParent(a);
        int brep = getParent(b);

        if(arep == brep)
            return;
        
        parent[brep] = arep;
        size[arep] += size[brep];
        curGrps--;
    }
};

class Solution {
private:
    int encode(int x, int y, int m) {
        return (x * m) + y;
    }
    pair<int, int> decode(int pos, int m) {
        int x = pos / m;
        int y = pos % m;
        return {x, y};
    }
public:
    int minDays(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return -1;
        
        int n = grid.size(), m = grid[0].size();

        DSU dsu(n * m);
        set<int> st;

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) 
                    continue;
                dsu.reg(encode(i, j, m));
                st.insert(encode(i, j, m));
                for(auto &dir: dirs) {
                    int nX = i + dir[0];
                    int nY = j + dir[1];
                    if(nX < 0 || nX >= n || nY < 0 || nY >= m)
                        continue;
                    if(grid[nX][nY] == 0 || dsu.size[encode(nX, nY, m)] == 0)
                        continue;
                    
                    dsu.unionSets(encode(nX, nY, m), encode(i, j, m));
                }
            }
        }

        if(dsu.curGrps != 1)
            return 0;
        
        // for(int node: st)
        //     cout<<decode(node, m).first<<" "<<decode(node, m).second<<" ";
        // cout<<endl;

        int pNode = dsu.getParent(*st.begin());
        
        if(dsu.size[pNode] <= 2)
            return dsu.size[pNode];
    
        for(int ignoreNode: st)
        {
            DSU tmpdsu(n * m);
            for(int node: st)
            {
                if(node == ignoreNode)
                    continue;
                
                int i = decode(node, m).first, j = decode(node, m).second;
                tmpdsu.reg(node);

                for(auto &dir: dirs) {
                    int nX = i + dir[0];
                    int nY = j + dir[1];
                    if(nX < 0 || nX >= n || nY < 0 || nY >= m)
                        continue;
                    if(grid[nX][nY] == 0 || tmpdsu.size[encode(nX, nY, m)] == 0)
                        continue;
                    
                    tmpdsu.unionSets(node, encode(nX, nY, m));
                }
            }

            if(tmpdsu.curGrps != 1)
                return 1;
        }

        return 2;
    }
};
