class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]==0 || visited[row][col])
        return 0;

        visited[row][col] = true;
        return 1+ dfs(row+1, col, grid, visited)+
                  dfs(row-1, col, grid, visited)+
                  dfs(row, col+1, grid, visited)+
                  dfs(row, col-1, grid, visited);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxLand = 0;
        int maxArea = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                maxLand = dfs(row, col, grid, visited);
                maxArea = max(maxArea, maxLand);
            }
        }
        return maxArea;
    }
};