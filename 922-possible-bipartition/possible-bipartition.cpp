class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& groups){
        for(int nei : graph[node]){
            if(groups[nei] == -1){
                groups[nei] = 1 - groups[node];

                if(!dfs(nei, graph, groups))
                return false;
            }
            else if(groups[node] == groups[nei]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        vector<int> groups(n+1, -1);
        for(auto &it : dislikes){
            int a = it[0];
            int b = it[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(groups[i] == -1){
                groups[i]=0;

                if(!dfs(i, graph, groups))
                return false;
            }
        }
        return true;
    }
};