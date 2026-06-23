class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;   
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.') continue;
                string row_record = to_string(val) + " in row " + to_string(r);
                string col_record = to_string(val) + " in col " + to_string(c);
                string box_record = to_string(val) + " in box " + to_string(r / 3) + "-" + to_string(c / 3);
                if (seen.count(row_record) || seen.count(col_record) || seen.count(box_record)) {
                    return false;
                }
                seen.insert(row_record);
                seen.insert(col_record);
                seen.insert(box_record);
            }
        }
        return true;
    }
};