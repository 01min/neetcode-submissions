class Solution {
public:
    int lv(string c){
        if(c=="*"||c=="/")return 2;
        else return 1;
    }
    bool isoperator(string s){
        if(s=="+" || s=="-"||s=="*"||s=="/")return true;
        else return false;
    }
    int calculator(int a,int b,string s){
        if(s=="+")return a+b;
        else if(s=="-")return a-b;
        else if(s=="*")return a*b;
        else if(s=="/")return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        int currentans=0;
        string currentoperator;
        for(string &s:tokens){
            int numofs;
            if(!isoperator(s)){st.push(s);}
            else{
                int b=stoi(st.top());
                st.pop();
                int a=stoi(st.top());
                st.pop();
                currentans=calculator(a,b,s);
                st.push(to_string(currentans));
                }
            }
            return stoi(st.top());
        }
        
    
};
