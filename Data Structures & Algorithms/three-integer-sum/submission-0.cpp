class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left=0;
        sort(nums.begin(),nums.end());
        int right=nums.size()-1;
    vector<vector<int>>v;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0)break;
        if(i>0 &&nums[i]==nums[i-1])continue;
        left=i+1;right=nums.size()-1;
        while(left<right){
        if(nums[left]+nums[right]==(-1*nums[i])){if(nums[left-1]==nums[left] &&right+1<nums.size()&& nums[right+1]==nums[right] ){left++;right--;}else{v.push_back({nums[left],nums[right],nums[i]});left++;right--;}}
        else if((nums[left]+nums[right]<(-1*nums[i])))left++;
        else if(nums[left]+nums[right]>(-1*nums[i]))right--;
    }
    }
        return v;
    }
};
