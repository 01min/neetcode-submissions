class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return bs(0,matrix.size()*matrix[0].size()-1,matrix,target);
    }
    bool bs(int left,int right,vector<vector<int>>&matrix,int target){
        int mid=(left+right)/2;
        int n=matrix[0].size();
        if(left>right)return false;
        else if(matrix[mid/n][mid%n]==target)return true;
        else if(matrix[mid/n][mid%n]<target) return bs(mid+1,right,matrix,target);
        else if(matrix[mid/n][mid%n]>target)return bs(left,mid-1,matrix,target);
    }
};
