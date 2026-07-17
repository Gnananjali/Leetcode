class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minutes=0;
        queue<pair<int,int>> q;
        int fresh=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==2){
                    q.push({row, col});
                }else if(grid[row][col]==1){
                    fresh++;

                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            
            int size = q.size();
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();

                int row = node.first;
                int col = node.second;

                for(int i=0;i<4;i++){
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]==1){
                        grid[newRow][newCol] = 2;
                        fresh--;
                        q.push({newRow, newCol});
                    }
                }
            }
                    if(!q.empty()){
                        minutes++;
                    }
                    
                
                
        }
        if(fresh==0) return minutes;
        else return -1;
    }
};