class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        
            for(auto& p:prerequisites){
                int course = p[0];
                int prerequisite = p[1];
                adj[prerequisite].push_back(course);
                indegree[course]++;
            }
        
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int nei : adj[node]){
                indegree[nei]--;

                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};