class Solution {
public:
    int search(vector<int>& nums, int target) {
        return bs(0,nums.size()-1,nums,target);
    }
    int bs(int left,int right,vector<int>&nums,int target){
        int mid=(left+right)/2;
        if(left>right)return -1;
        if(nums[mid]==target)return mid;
        else if(nums[mid]<target)return bs(mid+1,right,nums,target);
        else if(target<nums[mid])return bs(left,mid-1,nums,target);

    }

};
