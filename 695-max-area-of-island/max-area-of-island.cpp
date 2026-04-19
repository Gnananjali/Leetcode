class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        if(n ==0 && m == 0){
            return 0;
        }

    function<int(int,int)> dfs = [&](int i, int j){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0){
            return 0;
        }
        grid[i][j] = 0;

    int area = 1;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    
    for(int d=0;d<4;d++){
        int ni = i + dx[d];
        int nj = j + dy[d];

        area += dfs(ni, nj);

    }
    return area;
    };

    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                int area = dfs(i, j);
                maxArea = max(maxArea, area);
            }
        }
        }
        return maxArea;
    }
};