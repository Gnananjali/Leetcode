class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        
        int m = grid.size();
        int n = grid[0].size();

        if(row>=m || col>=n || row<0 || col<0 || grid[row][col]!=0|| visited[row][col]) return true;

        visited[row][col] = true;
        bool closed = (row>0 && col>0 && row<m-1 && col<n-1);

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int k=0;k<4;k++){
            int nr = row + dr[k];
            int nc = col + dc[k];

            if(!dfs(nr, nc, grid, visited)) closed = false;
            
        }
        return closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!visited[row][col] && grid[row][col] == 0){
                    if(dfs(row, col, grid, visited)){
                    count++;
                    }
                    
                }
            }
        }
        return count;
    }
};