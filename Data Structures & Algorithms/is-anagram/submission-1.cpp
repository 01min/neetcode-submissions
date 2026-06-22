class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        int same[26]={0};
        for(int i:s){same[i-'a']++;}
        for(int i:t){same[i-'a']--;}
        for(int i:same){if(i!=0)return false;}
        return true;
    }
};
