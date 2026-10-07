class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& image, int oldColor, int newColor){
        int n = image.size();
        int m = image[0].size();

        if(row>=n || col>=m || row<0 || col<0 || image[row][col]!=oldColor) return;
        image[row][col] = newColor;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for(int k=0;k<4;k++){
            int nr = row + dr[k];
            int nc = col + dc[k];

            dfs(nr, nc, image, oldColor, newColor);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];

        if(oldColor == color) return image;

        dfs(sr, sc, image, oldColor, color);

        return image;
    }
};