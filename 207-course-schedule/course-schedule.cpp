class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state){
        state[node] = 1;
        for(int nei : graph[node]){
            if(state[nei] == 1){
                return true;
            }
            if(state[nei] == 0){
                if(dfs(nei, graph, state))
                    return true;
            }
        }
        state[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &p : prerequisites){
            int course = p[0];
            int prerequisites = p[1];

            graph[prerequisites].push_back(course);
        }
        vector<int> state(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(state[i] == 0){
                if(dfs(i, graph, state))
                    return false;
            }
        }
        return true;
    }
};