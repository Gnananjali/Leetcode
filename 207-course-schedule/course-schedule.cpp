class Solution {
public:
    vector<int> bfs(int n, vector<vector<int>>& adj, vector<int>& indegree){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }
        return topo;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto& p : prerequisites){
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        vector<int> topo = bfs(n, adj, indegree);
        return topo.size()==n;
    }
};