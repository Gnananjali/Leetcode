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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int components = n;
        if(connections.size() < n-1) return -1;
        for(auto& e:connections){
            int u = e[0];
            int v = e[1];
            if(dsu.unite(u,v)){
                components--;
            }
        }
        return components-1;
    }
};