class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size(), m = grid[0].size();
        int fresh = 0;

        if(n == 0 && m == 0){
            return 0;
        }

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int minutes = 0;
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        while(!q.empty() && fresh>0){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto[x,y] = q.front();
                q.pop();

                for(int d=0;d<4;d++){
                    int ni = x + dx[d];
                    int nj = y + dy[d];
                    if(ni<n && nj<m && ni>=0 && nj>=0 && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        fresh--;
                        q.push({ni,nj});
                    }
                }
            }
            minutes++;
        }
        return (fresh==0)?minutes:-1;
    }
};