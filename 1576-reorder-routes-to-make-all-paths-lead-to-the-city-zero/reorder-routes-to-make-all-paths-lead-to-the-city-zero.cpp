class Solution {
public:

    void dfs(int node, vector<vector<pair<int, bool>>>& adj, int& count, vector<bool>& vis){
        vis[node] = true;
        for(auto &[nei, path] : adj[node]){
            if(!vis[nei]){
                if(path)
                count++;
                dfs(nei, adj, count, vis);
            }
            
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> adj(n);
        vector<bool> vis(n,false);
        int count = 0;
        for(auto& it:connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, true});
            adj[v].push_back({u, false});
        }
        dfs(0, adj, count, vis);
        return count;
    }
};