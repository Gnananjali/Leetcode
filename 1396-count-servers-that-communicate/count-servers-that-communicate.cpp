class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int m=grid.size();
        int n=grid[0].size();

        visited[row][col]=true;
        int count=1;

        for(int i=0;i<m;i++){
            if(!visited[i][col] && grid[i][col]==1){
                count += dfs(i, col, grid, visited);
            }
        }
        for(int j=0;j<n;j++){
            if(!visited[row][j] && grid[row][j]==1){
                count += dfs(row, j, grid, visited);
            }
        }

        return count;
    }
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1 && !visited[row][col]){
                
                    int size = dfs(row, col, grid, visited);
                
                    if(size > 1){
                        ans += size;
                    }
                }
            }
        }
        return ans;
    }
};