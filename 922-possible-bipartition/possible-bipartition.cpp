class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>>& adj, vector<int>& colors){
        colors[node] = color;
        for(int nei : adj[node]){
            if(colors[nei] == -1){
                if(!dfs(nei, 1-color, adj, colors))
                return false;
            }else if(colors[nei] == color){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> colors(n+1, -1);
        vector<vector<int>> adj(n+1);
        for(auto& e:dislikes){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<=n;i++){
            if(colors[i] == -1){
                if(!dfs(i, 0, adj, colors))
                return false;
            }
        }
        return true;
    }
};