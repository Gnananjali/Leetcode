class Solution {
public:
    vector<vector<bool>> visited;
    void dfs(int row, int col, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(row<0 || row >= m || col<0 || col >=n || visited[row][col] || grid[row][col]!='1') {
            return;
        }

        visited[row][col] = true;
        dfs(row-1, col, grid);
        dfs(row+1, col, grid);
        dfs(row, col-1, grid);
        dfs(row, col+1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    count++;
                    dfs(row, col, grid);
                }
            }
        }
        return count;
    }
};