class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited){
        visited[node] = true;

        for(int i:graph[node]){
            if(!visited[i]){
                dfs(i, graph, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    graph[i].push_back(j);
                }
            }
        }
        for(int x=0;x<n;x++){
            if(!visited[x]){
                count++;
                dfs(x, graph, visited);
            }
        }
        return count;
    }
};