class Solution {
public:
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
        stack<int>st;
        int currentans=0;
        string currentoperator;
        for(string &s:tokens){
            int numofs;
            if(!isoperator(s)){numofs=stoi(s);st.push(numofs);}
            else{
                int b=(st.top());
                st.pop();
                int a=(st.top());
                st.pop();
                currentans=calculator(a,b,s);
                st.push((currentans));
                }
            }
            return (st.top());
        }
        
    
};
