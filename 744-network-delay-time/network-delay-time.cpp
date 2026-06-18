class Solution {
public:
    vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& adj){
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;
        dist[start] = 0;
        pq.push({0, start});
        while(!pq.empty()){
            auto[d, node] = pq.top();
            pq.pop();
            if(d > dist[node]) continue;
            for(auto[nei, wt] : adj[node]){
                int newDist = d+wt;
                if(newDist < dist[nei]){
                    dist[nei]=newDist;
                    pq.push({newDist, nei});
                }
            }
        }
        return dist;

    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& t: times){
            int u = t[0];
            int v = t[1];
            int w = t[2];

            adj[u].push_back({v,w});
        }
        vector<int> dist = dijkstra(k, adj);
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
                ans = max(ans, dist[i]);
            }
            return ans;
        }
    
};