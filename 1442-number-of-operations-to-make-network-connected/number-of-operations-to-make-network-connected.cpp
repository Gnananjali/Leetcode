class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(int i : adj[node]){
            if(!vis[i])
                dfs(i, adj, vis);
            }
        }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0);
        if(connections.size() < n-1) return -1;

        vector<vector<int>> adj(n);
        for(auto &e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
            int num = 0;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    num++;
                    dfs(i, adj, vis);
                }
            }
        return num-1;
    }
};