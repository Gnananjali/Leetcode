class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>= n || vis[i][j] || grid[i][j]==0) return 0;
        vis[i][j] = true;
        return 1+
        dfs(i+1, j, grid, vis)+
        dfs(i-1, j, grid, vis)+
        dfs(i, j+1, grid, vis)+
        dfs(i, j-1, grid, vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int maxLand = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 &&!vis[i][j]){
                
                int area = dfs(i, j, grid, vis);
                
                maxLand = max(maxLand, area);
            }
            }
        }
       return maxLand;
    }
};