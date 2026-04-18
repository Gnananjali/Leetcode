class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxVal = 0;

        if(n==0 && m==0){
            return 0;
        }
        function <void(int,int,int&)> dfs = [&](int i, int j,int &count){
            if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
                return;
            }
            grid[i][j]=0;
            count++;

            vector<int> dx = {1,-1,0,0};
            vector<int> dy = {0,0,1,-1};

            for(int d=0;d<4;d++){
                int ni = i+dx[d];
                int nj = j+dy[d];

                
                    dfs(ni,nj,count);
                }
            };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int count=0;
                    dfs(i,j,count);
                    maxVal = max(maxVal, count);
                }
            }
        }
        return maxVal;
    }
};