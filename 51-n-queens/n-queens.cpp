class Solution {
public:
    bool issafe(int row, int col, vector<vector<string>>& ans, vector<string>& board, int n) {
        // Store original values to reset them for each direction check
        int duprow = row;
        int dupcol = col;

        // 1. Check upper-left diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // Reset variables to the current placement spot
        row = duprow;
        col = dupcol;

        // 2. Check straight left row (row stays the same, col goes left)
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        // Reset variables to the current placement spot
        row = duprow;
        col = dupcol;

        // 3. Check lower-left diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<string>& board, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (issafe(row, col, ans, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, ans, board, n);
        return ans;
    }
};
