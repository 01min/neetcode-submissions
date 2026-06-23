class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int maxnum=0;
        for(int i=0;i<nums.size();i++){st.insert(nums[i]);}
        for(int num:st){
            if(st.count(num-1))continue;
            int start=num;
            int index=1;
            while(st.count(start+1)){index+=1;start+=1;}
            maxnum=max(index,maxnum);
        }
        return maxnum;
    }
};
