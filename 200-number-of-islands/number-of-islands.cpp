class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        int n = grid.size();
        int m = grid[0].size();

        
        if(row>=n || col>=m || row<0 || col<0 || visited[row][col] || grid[row][col]!='1') return;

        visited[row][col] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int k=0;k<4;k++){
            int nr = row + dr[k];
            int nc = col + dc[k];

            dfs(nr, nc, grid, visited);
        }

       /* dfs(row-1, col, grid, visited);
        dfs(row+1, col, grid, visited);
        dfs(row, col-1, grid, visited);
        dfs(row, col+1, grid, visited);  */

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};