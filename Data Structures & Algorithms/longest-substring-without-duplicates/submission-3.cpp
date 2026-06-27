class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxnum=0;
        int left=0;
        int right=0;
        int index=0;
        unordered_set<char>st;
        while(right<s.length()&&left<=right){
            
            if(!st.count(s[right])){st.insert(s[right]);index+=1;maxnum=max(maxnum,index);right+=1;}
            else{st.erase(s[left]);left+=1;index-=1;}

        }
        return maxnum;
    }

};
