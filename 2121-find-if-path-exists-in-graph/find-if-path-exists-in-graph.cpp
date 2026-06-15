class Solution {
public:
    bool dfs(int node, int destination, vector<vector<int>>& adj, vector<bool>& vis){
        if(node == destination) return true;

        vis[node] = true;
        for(int i:adj[node]){
            if(!vis[i]){
                if(dfs(i, destination, adj, vis))
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);

        }
        return dfs(source, destination, adj, vis);
    }
};