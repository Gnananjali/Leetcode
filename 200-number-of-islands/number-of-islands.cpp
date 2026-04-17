class Solution {
public:
/* 
in this code we need to take n and m as size of rows and columns of the grid and initilaize count as 0.

if n and m are 0 then return 0.

we will create a function for dfs with parameters as i and j and here '&' is used for representing every i and j in the grid.

we will check if i and j are less than 0 or greater than their sizes (n and m), if it is true will return or else mark the grid[i][j] as 0. It means we have visited the node and marked it as 0.

then we will check the sides of the node which we visited up,down,left and right and same goes to them if they are equal to 1 we will mark them as 0.

for i and j if grid[i][j] is 1 we will increment the count and transfer the i and j to the dfs function.

at last return count.

*/
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