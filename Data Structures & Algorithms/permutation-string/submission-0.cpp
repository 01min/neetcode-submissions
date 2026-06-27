class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int>c1(26,0);
        vector<int>c2(26,0);
        for (char c : s1) {
            c1[c - 'a']++;
        }
        int left=0;
        for(int right=0;right<s2.length();right++){
            c2[s2[right] - 'a']++;
       
        if (right - left + 1 > s1.length()) {
            c2[s2[left] - 'a']--;
            left++; 
            }
        if (right - left + 1 == s1.length()) {
        if (c1 == c2) {
            return true; 
        }
    }
    }
    return false;
    }
};
