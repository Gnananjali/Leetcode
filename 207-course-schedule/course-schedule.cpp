class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            for(int neighbor : adj[i]){
                indegree[neighbor]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int neighbor:adj[node]){
                indegree[neighbor]--;

                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        if(ans.size()==numCourses) return true;
        return false;
    }
};