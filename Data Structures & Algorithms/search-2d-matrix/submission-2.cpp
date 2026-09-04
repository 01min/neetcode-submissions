class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        set<int>whole;
        for(auto &i:matrix){
            for(int &j:i){
                whole.insert(j);
            }
        }
        if(whole.count(target))return true;
        else return false;
    }
};
