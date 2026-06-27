class Solution {
public:
    int characterReplacement(string s, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<char,int>mp;
        int max_count=0;
        int max_len=0;
        int left=0;
        for(int right=0;right<s.length();right++){
            mp[s[right]]++;
            max_count=max(max_count,mp[s[right]]);
        while((right-left+1)-max_count>k){
            mp[s[left]]--;
            left++;
        }
        max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
