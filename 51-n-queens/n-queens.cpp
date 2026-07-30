class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {

        // Check same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        int i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        // Check upper-right diagonal
        i = row;
        j = col;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        return true;
    }

    void solve(int row, vector<string>& board,
               vector<vector<string>>& ans, int n) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, board, n)) {

                board[row][col] = 'Q';

                solve(row + 1, board, ans, n);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(0, board, ans, n);

        return ans;
    }
};