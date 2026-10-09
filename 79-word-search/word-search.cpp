class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int index, int r, int c){
        int m = board.size();
        int n = board[0].size();
        if(index == word.size()) return true;

        if(r>=m || c>=n || r<0 || c<0 || board[r][c] != word[index]) return false;

        char temp = board[r][c];
        board[r][c] = '#';

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(dfs(board, word, index+1, nr, nc)){

            board[r][c] = temp;
            return true;
            }
        }
        board[r][c] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(dfs(board, word, 0, r, c)){
                    return true;
                }
            }
        }
        return false;
    }
};