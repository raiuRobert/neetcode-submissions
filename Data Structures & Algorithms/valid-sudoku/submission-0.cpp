class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // PASS 1: rows
        for (int r = 0; r < 9; r++) {
            unordered_set<char> seen;
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch == '.') continue;
                if (seen.count(ch)) return false;
                seen.insert(ch);
            }
        }

        // PASS 2: columns
        for (int c = 0; c < 9; c++) {
            unordered_set<char> seen;
            for (int r = 0; r < 9; r++) {
                char ch = board[r][c];
                if (ch == '.') continue;
                if (seen.count(ch)) return false;
                seen.insert(ch);
            }
        }

        // PASS 3: 3x3 boxes
        for (int box = 0; box < 9; box++) {
            unordered_set<char> seen;
            int startRow = (box / 3) * 3;
            int startCol = (box % 3) * 3;
            for (int r = startRow; r < startRow + 3; r++) {
                for (int c = startCol; c < startCol + 3; c++) {
                    char ch = board[r][c];
                    if (ch == '.') continue;
                    if (seen.count(ch)) return false;
                    seen.insert(ch);
                }
            }
        }

        return true;
    }
};