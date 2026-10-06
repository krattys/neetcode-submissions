class Solution {
public:
    bool isValidRow(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            set<char> row;
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                if (row.find(board[r][c]) != row.end()) {
                    return false;
                }
                row.insert(board[r][c]);
            }
        }

        return true;
    }

    bool isValidColumn(vector<vector<char>> &board) {
        for (int c = 0; c < 9; c++) {
            set<char> cols;
            for (int r = 0; r < 9; r++) {
                if (board[r][c] == '.') continue;
                if (cols.find(board[r][c]) != cols.end()) return false;
                cols.insert(board[r][c]);
            }
        }

        return true;
    }

    bool isSubboxValid(vector<vector<char>> &board, int r, int c) {
        set<char> subbox;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[r+i][c+j] == '.') continue;
                if (subbox.find(board[r+i][c+j]) != subbox.end()) return false;
                subbox.insert(board[r+i][c+j]);
            }
        }

        return true;
    }

    bool isValidSuboxes(vector<vector<char>> &board) {
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {
                if (!isSubboxValid(board, r, c)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidRow(board) && isValidColumn(board) && isValidSuboxes(board);
    }
};
