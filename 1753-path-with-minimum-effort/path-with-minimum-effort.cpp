class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        effort[0][0] = 0;
        priority_queue<tuple<int, int, int>,
            vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        pq.push({0, 0, 0});
        while(!pq.empty()){
        auto [currentEffort, r, c] = pq.top();
        pq.pop();
        if(currentEffort > effort[r][c]) continue;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr<0 || nc<0 || nr>=m || nc>=n) continue;

            if(r == m-1 && c == n-1) return currentEffort;

            int edgeEffort = abs(heights[r][c] - heights[nr][nc]);
            int newEffort = max(currentEffort, edgeEffort);


            if(newEffort < effort[nr][nc]){
                effort[nr][nc] = newEffort;
                pq.push({newEffort, nr, nc});
            }
        }
        
        }
        return 0;
    }
};