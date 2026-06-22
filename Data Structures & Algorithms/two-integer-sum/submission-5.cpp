
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(mp.count(complement)){return {mp[complement],i};}
            mp[nums[i]]=i;
        }
        return {};
    }
};
