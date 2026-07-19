class DisjointSet {
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
            if(parent[node]==node) {
            return node;
        }
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    ds.UnionbySize(i,j);
                }
            }
        }
        int provinces=0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i){
                provinces++;
            }
        }
        return provinces;
    }
};