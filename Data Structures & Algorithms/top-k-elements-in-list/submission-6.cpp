class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second>b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
        }
        int t=0;
        vector<pair<int,int>>tmp;
        for(auto &i:mp){
            tmp.push_back({i.first,i.second});
        }
        sort(tmp.begin(),tmp.end(),cmp);
        vector<int>ans;
        for(auto &i:tmp){
            if(t<k){
                ans.push_back(i.first);
                t++;
            }
            else{
                break;
            }

        }
        return ans;
    }
};
