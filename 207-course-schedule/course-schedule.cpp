class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state, stack<int>& st){
        state[node] = true;
        
        for(int nei : adj[node]){
            if(state[nei] == 1){
                return false;
            }
            if(state[nei]==0){
                if(!dfs(nei, adj, state, st)){
                    return false;
                }
            }
        }
        state[node] = 2;
        st.push(node);
        return true;
            
        
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        stack<int> st;
        for(auto &it : prerequisites){
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++){
            if(state[i] == 0){
                if(!dfs(i, adj, state, st)){
                    return {};
                }
                    
                
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans.size()==numCourses?true:false;
    }
};