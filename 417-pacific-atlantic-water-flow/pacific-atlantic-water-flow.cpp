class Solution {
public:
    int m,n;
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean){
        ocean[r][c] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr>=0 && nc>=0 && nr<m && nc<n && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]){
                dfs(nr, nc, heights, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         m=heights.size();
         n=heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int r=0;r<m;r++){
            dfs(r, 0, heights, pacific);
        }
        for(int c=0;c<n;c++){
            dfs(0, c, heights, pacific);
        }
        for(int r=0;r<m;r++){
            dfs(r, n-1, heights, atlantic);
        }
        for(int c=0;c<n;c++){
            dfs(m-1, c, heights, atlantic);
        }

        vector<vector<int>> ans;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(pacific[r][c] && atlantic[r][c])
                ans.push_back({r, c});
            }
        }
        return ans;
    }
};