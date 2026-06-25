class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        for(int i=0;i<temperatures.size();i++){
            int j=i+1;
            int tmptmp=0;
            int tmpans=0;
           for(int j = i + 1; j < temperatures.size(); j++){
            if(temperatures[j] > temperatures[i]){
                tmpans = j - i; 
                break; 
            }
        }
           ans.push_back(tmpans);
           
        }
        return ans;
    }
};
