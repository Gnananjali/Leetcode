class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int minutes=0;
        int fresh=0;
        queue<pair<int, int>> q;
        

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 2){
                    q.push({row, col});
                }else if(grid[row][col] == 1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;

                for(int k=0;k<4;k++){
                    int newr = r + dr[k];
                    int newc = c + dc[k];

                    if(newr >= 0 && newc >= 0 && newr < m && newc < n && grid[newr][newc] == 1){

                    
                        grid[newr][newc] = 2;
                        fresh--;
                        q.push({newr, newc});
                    }
                    
                }
            }
            minutes++;
        }
        
        return fresh==0 ? minutes-1 : -1;  

    }
};