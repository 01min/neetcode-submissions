class Solution {
public:
    bool isValid(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        stack<char>st;
        for(char c:s){
            if(c=='['||c=='('||c=='{'){st.push(c);}
            else if (st.empty())return false;
            else if((c==']'&&st.top()=='[')||(c==')'&&st.top()=='(')||(c=='}'&&st.top()=='{')){st.pop();}else return false;

        }
        return st.empty();
    }
};
