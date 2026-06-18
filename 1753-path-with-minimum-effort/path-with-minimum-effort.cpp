class Solution {
public:
    int dijkstra(vector<vector<int>>& heights){
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
        > pq;

        effort[0][0] = 0;
        pq.push({0, 0, 0});

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int d = curr[0];
            int r = curr[1];
            int c = curr[2];

            if(r == m-1 && c == n-1) return d;
            if(d > effort[r][c]) continue;

            for(int k=0;k<4;k++){
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr<0 || nc<0 || nr>=m || nc>=n) continue;

                int wt = abs(heights[r][c] - heights[nr][nc]);

                int newEffort = max(d, wt);
                if(newEffort < effort[nr][nc]){
                    effort[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }
        return 0;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        return dijkstra(heights);
    }
};