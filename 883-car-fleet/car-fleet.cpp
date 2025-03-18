class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector <pair<int,double>> v;
        for(int i = 0 ; i < speed.size() ; i++)
            v.push_back({position[i] , (target - position[i]) / (speed[i] * 1.0)});
        sort(v.rbegin() , v.rend());
        double slowest = v[0].second;
        int fleets = 1;
        for(int i = 0 ; i < v.size() ; i++)
            if(v[i].second > slowest)
                slowest = v[i].second , fleets++;
        return fleets;
    }
};