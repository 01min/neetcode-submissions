class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>lans(nums.size(),1);
        vector<int>rans(nums.size(),1);
        for(int i=1;i<nums.size();i++){lans[i]=lans[i-1]*nums[i-1];}
        for(int i=nums.size()-2;i>=0;i--){rans[i]=rans[i+1]*nums[i+1];}
        vector<int>real_ans(nums.size(),1);
        for(int i=0;i<real_ans.size();i++){real_ans[i]=lans[i]*rans[i];}
        return real_ans;
    }
};
