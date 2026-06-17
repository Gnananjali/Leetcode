class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state, stack<int>& st){
        if(state[node]==1) return false;
        if(state[node]==2) return true;
        state[node] = 1;
        for(int nei : adj[node]){
            if(!dfs(nei, adj, state, st))
                return false;
            }
            state[node] = 2;
        
        st.push(node);
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> state(n, 0);
        vector<vector<int>> adj(n);
        stack<int> st;
        for(auto& p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        for(int i=0;i<n;i++){
            if(state[i] == 0){
                if(!dfs(i, adj, state, st))
                return {};
            }
        }
        vector<int> order;
        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }
       
        return order;
    }
};