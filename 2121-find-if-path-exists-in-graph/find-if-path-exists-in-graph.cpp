class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, int destination, vector<bool>& vis){
        vis[node] = true;
        if(node == destination) return true;
        for(int nei:adj[node]){
            if(!vis[nei]){
                if(dfs(nei, adj, destination, vis)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(auto& it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        if(dfs(source, adj, destination, vis))
            return true;
        return false;
    }
};