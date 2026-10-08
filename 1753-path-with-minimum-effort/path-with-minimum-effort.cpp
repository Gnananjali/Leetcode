class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});

        while(!pq.empty()){
            auto [currentEffort, row, col] = pq.top();
            pq.pop();
            if(currentEffort > effort[row][col]) continue;
            if(row == n-1 && col == m-1) return currentEffort;


            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};

            for(int k=0;k<4;k++){
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr>=n || nc>=m || nr<0 || nc<0) continue;

                int edgeEffort = abs(heights[row][col] - heights[nr][nc]);
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