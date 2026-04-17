class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        if(n == 0 && m == 0){
            return 0;
        }
        function<void(int,int)> dfs = [&](int i, int j){
            if(i<0 ||i>=n || j<0 || j>=m || grid[i][j]=='0'){
                return;
            }
            grid[i][j] = '0';

            dfs(i+1, j);
            dfs(i, j+1);
            dfs(i-1, j);
            dfs(i, j-1);
        };


        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j);
                }
            }
        }
        return count;
    }
};