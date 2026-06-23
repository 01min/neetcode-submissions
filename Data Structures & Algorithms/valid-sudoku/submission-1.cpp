class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>seen;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                string sr="row"+to_string(i)+"val"+to_string(board[i][j]);
                string sc="col"+to_string(j)+"val"+to_string(board[i][j]);
                string sbl="row"+to_string(i/3)+"col"+to_string(j/3)+to_string(board[i][j]);
                if(seen.count(sr)||seen.count(sc)||seen.count(sbl)){return false;}
                seen.insert(sr);
                seen.insert(sc);
                seen.insert(sbl);
            }
        }
        return true;
        }
};