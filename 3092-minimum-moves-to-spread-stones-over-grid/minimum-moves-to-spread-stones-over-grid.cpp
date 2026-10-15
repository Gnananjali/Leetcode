class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> extra, empty;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] > 1){
                    for(int k=1;k<grid[i][j];k++){
                        extra.push_back({i, j});
                    }
                }else if(grid[i][j] == 0){
                    empty.push_back({i, j});
                }
            }
        }

        int minMoves=INT_MAX;
        sort(empty.begin(), empty.end());
        do {
            int total=0;
            for(int i=0;i<extra.size();i++){
                auto [r1, c1] = extra[i];
                auto [r2, c2] = empty[i];

                int dist = abs(r1-r2) + abs(c1-c2);
                total += dist;
            }
            minMoves = min(minMoves, total);
        }while (next_permutation(empty.begin(), empty.end()));

        return minMoves;
    }
};