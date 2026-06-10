class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state){
        if(state[node] == 1) return true;
        if(state[node] == 2) return false;
        state[node] = 1;

        for(int i : adj[node]){
            if(dfs(i, adj, state)) return true;
        }
         state[node] = 2;
         return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for(auto &i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> state(n,0);
        for(int i=0;i<n;i++){
            if(state[i]==0){
                if(dfs(i, adj, state)) return false;
            }
        }
        return true;
    }
};