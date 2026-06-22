class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<string,vector<string>>vmp;
        for(string s:strs){
            string key=s;
            sort(key.begin(),key.end());
            vmp[key].push_back(s);
        }  
        vector<vector<string>>vv;
        for(auto&i:vmp){
            vv.push_back(i.second);
        }
        return vv;
    }
};
