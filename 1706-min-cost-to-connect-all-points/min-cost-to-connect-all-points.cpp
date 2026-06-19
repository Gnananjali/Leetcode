class DSU {
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return false;
        if(size[pu]<size[pv])
        swap(pu,pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt = 
                abs(points[i][0]-points[j][0]) + 
                abs(points[i][1]-points[j][1]);

                edges.push_back({wt, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int cost = 0;
        DSU dsu(n);
        for(auto& p:edges){
            int wt = p[0];
            int u = p[1];
            int v = p[2];
            if(dsu.unite(u,v))
            cost += wt;
        }
        return cost;
    }
};