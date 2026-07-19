class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &it:times){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
        }
        vector<int> distance(n+1, INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        distance[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int dist = curr.first;
            int node = curr.second;

            if(dist > distance[node]){
                continue;
            }
            for(auto &it:adj[node]){
                int neighbor = it.first;
                int weight = it.second;

                if(distance[node] + weight < distance[neighbor]){
                    distance[neighbor] = distance[node] + weight;

                    pq.push({distance[neighbor], neighbor}); 
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(distance[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, distance[i]);
        }
        return ans;
    }
};