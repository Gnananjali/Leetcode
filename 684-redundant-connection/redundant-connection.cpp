class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void UnionbySize(int u, int v){
        int parentU = findParent(u);
        int parentV = findParent(v);
        if(parentU == parentV) return;

        if(size[parentU] < size[parentV]){
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }else{
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];

            if(ds.findParent(u) == ds.findParent(v)){
                return {u, v};
            } else{
                ds.UnionbySize(u, v);
            }
        }
        return {};
    }
};