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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);
        for(auto& e:edges){
            int u = e[0];
            int v = e[1];
            if(dsu.find(u) == dsu.find(v)){
                return e;
            }
            dsu.unite(u,v);
        }
        return {};
    }
};