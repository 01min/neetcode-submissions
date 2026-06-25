class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n=temperatures.size();
       vector<int>ans(n,0);
       stack<int>st;
       
       for(int i=0;i<n;i++){
        int tmpans=0;
        int preindex=0;
            while((!st.empty())&& temperatures[i]>temperatures[st.top()]){preindex=st.top();tmpans=i-st.top();ans[st.top()]=(tmpans);st.pop();}
            st.push(i);
            
       }
        return ans;
    }
};
