class Solution {
public:
    bool isPalindrome(string s) {
        string frontp;
        string backp;
        for(int i=s.length()-1;i>=0;i--){if(s[i]<='Z' && s[i]>='A'){s[i]-='A';s[i]+='a';}if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))backp+=(s[i]);}
        for(int i=0;i<s.length();i++){if(s[i]<='Z' && s[i]>='A'){s[i]-='A';s[i]+='a';}if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))frontp+=(s[i]);}
        if(frontp==backp)return true;
        else return false;
    }
};
