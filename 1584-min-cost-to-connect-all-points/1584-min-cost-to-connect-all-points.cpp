class DisjointSetUnion {
    vector<int> parent, size;
    public:
    DisjointSetUnion(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        else {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
    }

};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>> dist;
        for(int i=0;i<points.size();i++) {
            for(int j= i+1;j<points.size();j++) {
                int manhattan_distance = abs(points[j][0]-points[i][0]) + abs(points[j][1] - points[i][1]);
                dist.push_back({manhattan_distance, {i, j}});
            }
        }
        sort(dist.begin(), dist.end());
        int cost = 0;
        DisjointSetUnion dsu(points.size() + 1); 
        for(int i=0;i<dist.size();i++) {
            if(dsu.findParent(dist[i].second.first) != dsu.findParent(dist[i].second.second)) {
                cost += dist[i].first;
                dsu.unionBySize(dist[i].second.first, dist[i].second.second);
            }
        }
        return cost;
    }
};