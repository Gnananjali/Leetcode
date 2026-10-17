class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<pair<int, int>> q;
        
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, -1));

        for(auto& source : sources){
            int r = source[0];
            int c = source[1];
            int color = source[2];

            q.push({r, c});
            grid[r][c] = color;
            dist[r][c] = 0;
        }
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto [r, c] = q.front();
                q.pop();

                

                for(int k=0;k<4;k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr<0 || nc<0 || nr>=n || nc>=m ) continue;
                    int newDist = dist[r][c]+1;
                    if(dist[nr][nc] == -1){
                        dist[nr][nc] = newDist;
                        grid[nr][nc] = grid[r][c];
                        q.push({nr, nc});
                    }else if(dist[nr][nc] == newDist){
                        grid[nr][nc] = max(grid[nr][nc], grid[r][c]);
                    }
                }
            }
        }
        return grid;
    }
};