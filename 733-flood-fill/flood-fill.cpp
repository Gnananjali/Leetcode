class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, int oldcolor, int newcolor){
        int m = image.size();
        int n = image[0].size();
        if(row<0 || row>=m || col<0 || col>=n || image[row][col] != oldcolor) return;
        
        image[row][col] = newcolor;
        dfs(row+1, col, image, oldcolor, newcolor);
        dfs(row-1, col, image, oldcolor, newcolor);
        dfs(row, col+1, image, oldcolor, newcolor);
        dfs(row, col-1, image, oldcolor, newcolor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int oldcolor = image[sr][sc];

        if(oldcolor == color) return image;
        
        
        dfs(sr,sc,image,oldcolor,color);
                
            
        
        return image;
    }
};