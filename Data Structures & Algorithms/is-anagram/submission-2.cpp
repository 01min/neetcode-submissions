class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp;
        for(char &ss:s){mp[ss]++;}
        for(char &ss:t){mp[ss]--;}
        for(auto &i:mp){if(i.second!=0)return false;}
        return true;
    }
};
