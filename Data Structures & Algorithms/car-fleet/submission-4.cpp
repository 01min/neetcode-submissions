class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>car;
        for(int i=0;i<speed.size();i++){
            double time=(double)(target-position[i])/speed[i];
            car.push_back({position[i],time});
        }
        sort(car.begin(),car.end());
        int fleet_count = 0;
        double max_time = 0.0;
        for(int i=car.size()-1;i>=0;i--){
            if(car[i].second > max_time){
                fleet_count++;         
                max_time = car[i].second; 
            }
        }
        return fleet_count;
    }
};
