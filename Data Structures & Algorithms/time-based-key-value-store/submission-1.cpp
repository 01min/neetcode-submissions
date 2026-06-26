class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>>db;
public:
    TimeMap() {
       
    }
    
    void set(string key, string value, int timestamp) {
        db[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(db.find(key)==db.end())return "";
        auto pairs=db[key];
        int left = 0;
        int right = pairs.size() - 1;
        string ans = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (pairs[mid].first <= timestamp) {
                ans = pairs[mid].second;
                left = mid + 1;          
            } else {
                right = mid - 1; 
            }
        }
        return ans;
    }
};
