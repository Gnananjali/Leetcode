class Solution {
public:
    bool dfs(int node, int destination, vector<vector<int>>& graph, vector<bool>& visited){
        visited[node] = true;

        if(node == destination) return true;
        for(int i:graph[node]){
            if(!visited[i]){
                if(dfs(i, destination, graph, visited))
                return true;
            }
            
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);

        for(auto x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        return dfs(source, destination, graph, visited);
    }
};