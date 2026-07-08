class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>st;
        for(int &n:nums){if(st.count(n))return true;st.insert(n);}
        return false;
    }
};