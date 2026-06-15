class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newcolor){
        int m = image.size();
        int n = image[0].size();

        if(r<0||c<0||r>=m||c>=n) return;
        if(image[r][c] != oldColor)
        return;
        image[r][c] = newcolor;

        dfs(image, r+1, c, oldColor, newcolor);
        dfs(image, r-1, c, oldColor, newcolor);
        dfs(image, r, c+1, oldColor, newcolor);
        dfs(image, r, c-1, oldColor, newcolor);

        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;
        dfs(image, sr, sc, oldColor, color);
        return image;
    }
};